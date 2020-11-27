#include "RenderFacade.h"

/// <summary>
/// Inits the renderFacade. This class gives all logic to the correct classes.
/// </summary>
RenderFacade::RenderFacade(cbPassCameraDimension f, void* p)
{
	frameManager = std::make_unique<FrameManager>();
	renderer = std::make_unique<Renderer>(f, p);
	drawController = std::make_unique<DrawController>(renderer);
}

std::string RenderFacade::constructorError() const noexcept
{
	return "SDLFacade constructor is not called";
}

/// <summary>
/// This function loads in a texture in the drawController.
/// </summary>
/// <param name="path">The path of the .png for the texture.</param>
/// <returns>Returns a SDL_Texture to render.</returns>
SDL_Texture* RenderFacade::loadTexture(const std::string& path) const
{
	return drawController->loadTexture(path.c_str());
}

/// <summary>
/// Calls the setFrameStart from the frameManager
/// </summary>
void RenderFacade::setFrameStart() const
{
	frameManager->setFrameStart();
}

/// <summary>
/// Calls the setFrameDelay from the frameManager
/// </summary>
void RenderFacade::setFrameDelay() const
{
	frameManager->setFrameDelay();
}

/// <summary>
/// Prepares a texture of text to be drawn to the screen.
/// </summary>
/// <param name="path">The path of the font of the texture.</param>
/// <param name="text">The string of text for the label.</param>
/// <param name="colour">The colour of the text.</param>
/// <param name="transform">The x and y of the text.</param>
/// <param name="fontSize">The size of the text.</param>
void RenderFacade::drawTexture(const std::string& path, const std::string& text, const Colour& colour, const Transform& transform, int fontSize) const
{
	SDL_Texture* textTexture = drawController->loadFont(text, path, colour, fontSize);
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	SDL_QueryTexture(textTexture, NULL, NULL, &source.w, &source.h);

	SDL_Rect destination;
	destination.x = transform.position.x;
	destination.y = transform.position.y;
	destination.w = source.w * transform.scale.x;
	destination.h = source.h * transform.scale.y;

	drawController->drawTexture(textTexture, source, destination, flip);
}

/// <summary>
/// Prepares a texture to be drawn to the screen.
/// </summary>
/// <param name="path">The path of the .png of the texture.</param>
/// <param name="transform">The Transform Rectangle</param>
/// <param name="coordinates">The x and y of the texture.</param>
/// <param name="sourceDimensions">The dimensions of the texture.</param>
/// <param name="row">The row of which animation, in case its animated.</param>
/// <param name="frames">The total animation frames in case its animated</param>
/// <param name="speed">The speed of the animation in case its animated</param>
/// <param name="animated">A boolean to represent if it is animated or not.</param>
/// <param name="flipped">A boolean to represent if it is flipped or not.</param>
void RenderFacade::drawTexture(const std::string& path, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimensions, int row, int frames, int speed, bool animated, bool flipped, bool isScreen) const
{
	Vector2D size;
	SDL_Texture* texture = drawController->loadTexture(path);
	renderer->drawTexture(texture, transform, coordinates, sourceDimensions, row, frames, speed, animated, flipped, isScreen);
}

/// <summary>
/// Inits the renderer.
/// </summary>
/// <param name="title">The title of the screen.</param>
/// <param name="width">The width of the screen.</param>
/// <param name="height">The height of the screen.</param>
/// <param name="fullscreen">If the screen is fullscreen or not.</param>
void RenderFacade::init(const std::string& title, int width, int height, bool fullscreen) const
{
	renderer->init(title, width, height, fullscreen);
}

/// <summary>
/// calls the clean methode in the renderer.
/// </summary>
void RenderFacade::clean() const
{
	renderer->clean();
}

/// <summary>
///  calls the beforeFrame methode in the renderer.
/// </summary>
void RenderFacade::beforeFrame() const
{
	renderer->beforeFrame();
}

/// <summary>
///  calls the afterFrame methode in the renderer.
/// </summary>
void RenderFacade::afterFrame() const
{
	renderer->afterFrame();
}

void RenderFacade::createCamera(const int x, const int y) const
{
	renderer->createCamera(x, y);
}

void RenderFacade::quitGame() const
{
	renderer->quitGame();
}

void RenderFacade::pauseGame() const
{
	renderer->pauseGame();
}

void RenderFacade::slowDownGame() const
{
	frameManager->slowDownGame();
}

void RenderFacade::speedUpGame() const
{
	frameManager->speedUpGame();
}

void RenderFacade::resetSpeedGame() const
{
	frameManager->resetSpeedGame();
}

int RenderFacade::getFPS() const
{
	return frameManager->getFPS();
}

std::tuple<int, int> RenderFacade::passPlayerPosition(const int x,const int y) const
{
	return renderer->updateCamera(x, y);
}
