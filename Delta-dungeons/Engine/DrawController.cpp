#include "DrawController.h"

DrawController::DrawController() {}

/// <summary>
/// The drawcontroller renders all the items in the game using a single renderer.
/// </summary>
/// <param name="r">The game renderer (SDL)</param>
DrawController::DrawController(std::shared_ptr<Renderer> r)
{
	renderer = r;
}

DrawController::~DrawController() {}

/// <summary>
/// The loadtexture method loads in a textures based on a given path. If the texture is already made, it will return it without creating a new one.
/// </summary>
/// <param name="path">The path of where the .png can be found.</param>
/// <returns>Returns a SDL_Texture to be drawn on the screen in another method.</returns>
SDL_Texture* DrawController::loadTexture(std::string path)
{
	if (textures.count(path))
	{
		return textures.find(path)->second;
	}
	else
	{
		SDL_Surface* tempSurface = IMG_Load(path.c_str());
		try {
			if (!tempSurface) {
				throw("Image not loaded in!");
			}
		}
		catch (std::string error) {
			std::cout << "Error: " << error << std::endl;
		}
		SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer.get()->sdlRenderer, tempSurface);
		textures.insert({ path, tex });
		SDL_FreeSurface(tempSurface);
		return tex;
	}
}

/// <summary>
/// The loadFont method loads in a textures based on a font and string of text. If the texture is already made, it will return it without creating a new one.
/// </summary>
/// <param name="text">This is the text that will appear in the label.</param>
/// <param name="font">This is the font the text will be written in.</param>
/// <param name="colour">This is the color the text will appear in.</param>
/// <param name="fontSize">This is the size of the text.</param>
/// <returns>Returns a SDL_Texture to be drawn on the screen in another method.</returns>
SDL_Texture* DrawController::loadFont(const std::string& text, const std::string& font, const Colour& colour, int fontSize)
{
	if (textures.count(text))
	{
		return textures.find(text)->second;
	}
	else {
		SDL_Color textColour = { colour.r, colour.g, colour.b, colour.a };
		SDL_Surface* tempSurface = TTF_RenderText_Blended(TTF_OpenFont(font.c_str(), fontSize), text.c_str(), textColour);
		try
		{
			if (!tempSurface)
			{
				throw("Font not loaded in!");
			}
		}
		catch (std::string error)
		{
			std::cout << "Error: " << error << std::endl;
		}
		SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer.get()->sdlRenderer, tempSurface);
		textures.insert({ text, tex }); // TODO: Meer unieke manier vinden om op te zoeken
		SDL_FreeSurface(tempSurface);
		return tex;
	}

}

/// <summary>
/// This function will draw the texture within the renderer with the given parameters.
/// </summary>
/// <param name="texture">This is the texture that will be drawn.</param>
/// <param name="source">The source is the width and height of the texture.</param>
/// <param name="destination">The destination is the X and Y position of the texture.</param>
/// <param name="flip">The flip is to determine if the texture needs to drawn upside down, flipped or normal. (Used for animations)</param>
void DrawController::drawTexture(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination, SDL_RendererFlip flip)
{
	try {
		if (renderer.get()->sdlRenderer == NULL) {
			throw("Renderer is NULL!");
		}
		else if (texture == NULL) {
			throw("SDL_Texture is NULL!");
		}
		SDL_RenderCopyEx(renderer.get()->sdlRenderer, texture, &source, &destination, NULL, NULL, flip);
		
	}
	catch (std::string error) {
		std::cout << "Error: " << error << std::endl;
	}
}

