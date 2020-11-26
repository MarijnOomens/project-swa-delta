#include "Renderer.h"

Renderer::Renderer()
{
	isRunning = false;
	isPaused = false;
	camera = { 0,0,0,0 };
	sdlRenderer = nullptr;
	sdlWindow = nullptr;

	alphaCounter = 0;
}

Renderer::~Renderer()
{
	SDL_DestroyWindow(sdlWindow);
	SDL_DestroyRenderer(sdlRenderer);
}

/// <summary>
/// The init methods creates all SDL required items to render a screen and textures within that screen.
/// </summary>
/// <param name="title">The title of the screen.</param>
/// <param name="width">The width of the screen.</param>
/// <param name="height">The height of the screen.</param>
/// <param name="fullscreen">If the screen is fullscreen or not.</param>
void Renderer::init(const std::string& title, int width, int height, bool fullscreen) 
{
	int flags = 0;
	if (fullscreen) 
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	try 
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
		{
			sdlWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
			if (!sdlWindow) 
			{
				isRunning = false;
				throw("Failed to create window!");
			}
			sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);
			if (sdlRenderer)
			{
				SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
			}
			else 
			{
				isRunning = false;
				throw("Failed to create Render!");
			}
			isRunning = true;
			isPaused = false;
		}
		else 
		{
			throw("Subsystems are not initialised!");
			isRunning = false;
		}
		if (TTF_Init() == -1)
		{
			std::cout << "Failed to initialise SDL_ttf!" << std::endl;
		}
	}
	catch (std::string error) 
	{
		std::cout << "Error: " << error << std::endl;
	}
}

void Renderer::createCamera(const int x, const int y) 
{
	int cameraX = x - 640;
	if (cameraX < 0) 
	{
		cameraX = 0;
	}
	int cameraY = y - 512;
	if (cameraY < 0)
	{
		cameraY = 0;
	}
	camera = { cameraX , cameraY, 4608, 4096 };
}

bool Renderer::checkCameraPosition(const Transform& transform) const
{
	if (transform.position.x >= camera.x - 128 && transform.position.x < camera.x + 1408 && transform.position.y >= camera.y - 128 && transform.position.y < camera.y + 1024)
	{
		return true;
	}
	return false;
}

std::tuple<int, int> Renderer::updateCamera(const int playerX,const int playerY)
{
	int differenceX = (playerX - (camera.x + 640));
	int differenceY = (playerY - (camera.y + 512));
	camera.x = camera.x + differenceX;
	camera.y = camera.y + differenceY;

	return std::make_tuple(differenceX, differenceY);
}

/// <summary>
/// This methods cleans the game files and destroys all sdl components to makes sure all memory is cleared.
/// </summary>
void Renderer::clean() const
{
	SDL_DestroyWindow(sdlWindow);
	SDL_DestroyRenderer(sdlRenderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

void Renderer::pauseGame()
{
	isPaused = !isPaused;
}

/// <summary>
/// This method pauzes the game.
/// </summary>
void Renderer::quitGame()
{
	isRunning = false;
	clean();
	exit(0);
}

/// <summary>
/// This methods cleans the screen before the frame is called.
/// </summary>
void Renderer::beforeFrame() const
{
	SDL_RenderClear(sdlRenderer);
}

/// <summary>
/// This method draws the screen after the frame is done.
/// </summary>
void Renderer::afterFrame() const
{
	SDL_RenderPresent(sdlRenderer);
}

void Renderer::drawTexture(SDL_Texture* texture, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimensions, int row, int frames, int speed, bool animated, bool flipped, bool isScreen)
{
	if (checkCameraPosition(transform) || isScreen)
	{
		SDL_Rect source;
		SDL_RendererFlip flip = SDL_FLIP_NONE;
		if (flipped)
			flip = SDL_FLIP_HORIZONTAL;

		source.w = sourceDimensions.x;
		source.h = sourceDimensions.y;
		source.x = coordinates.x;
		source.y = coordinates.y;

		if (animated)
		{
			source.x = source.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
			source.y = row * source.h;
		}

		if (transitioning)
		{
			SDL_SetTextureAlphaMod(texture, alphaCounter);
			if (alphaCounter >= 255)
			{
				alphaCounter = 0;
				transitioning = false;
			}
		} 
		else
		{
			SDL_SetTextureAlphaMod(texture, SDL_ALPHA_OPAQUE);
		}


		SDL_Rect destination;
		if (!isScreen)
		{
			destination.x = transform.position.x - camera.x;
			destination.y = transform.position.y - camera.y;
		}
		else
		{
			destination.x = transform.position.x;
			destination.y = transform.position.y;
		}
		destination.w = sourceDimensions.x * transform.scale.x;
		destination.h = sourceDimensions.y * transform.scale.y;

		try
		{
			if (sdlRenderer == NULL)
			{
				throw("Renderer is NULL!");
			}
			else if (texture == NULL)
			{
				throw("SDL_Texture is NULL!");
			}
			SDL_RenderCopyEx(sdlRenderer, texture, &source, &destination, NULL, NULL, flip);

		}
		catch (std::string error)
		{
			std::cout << "Error: " << error << std::endl;
		}
	}
}

/// <summary>
/// This function will draw the texture within the renderer with the given parameters.
/// </summary>
/// <param name="texture">This is the texture that will be drawn.</param>
/// <param name="source">The source is the width and height of the texture.</param>
/// <param name="destination">The destination is the X and Y position of the texture.</param>
/// <param name="flip">The flip is to determine if the texture needs to drawn upside down, flipped or normal. (Used for animations)</param>
void Renderer::drawText(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination, SDL_RendererFlip flip)
{
	if (transitioning)
	{
		SDL_SetTextureAlphaMod(texture, alphaCounter);

		if (alphaCounter >= 255)
		{
			alphaCounter = 0;
			transitioning = false;
		}
	}
	else
	{
		SDL_SetTextureAlphaMod(texture, SDL_ALPHA_OPAQUE);
	}

	try
	{
		if (sdlRenderer == NULL)
		{
			throw("Renderer is NULL!");
		}
		else if (texture == NULL)
		{
			throw("SDL_Texture is NULL!");
		}
		SDL_RenderCopyEx(sdlRenderer, texture, &source, &destination, NULL, NULL, flip);
	}
	catch (const std::string& error)
	{
		std::cout << "Error: " << error << std::endl;
	}
}

void Renderer::transition()
{
	transitioning = true;
}

void Renderer::checkTransition()
{
	if (transitioning) 
	{
		alphaCounter+=15;
	}
}
