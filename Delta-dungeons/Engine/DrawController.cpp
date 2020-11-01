#include "DrawController.h"

DrawController::DrawController() {}

DrawController::DrawController(std::shared_ptr<Renderer> r)
{
	renderer = r;
}

DrawController::~DrawController() {}

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
		textures.insert({ path,tex });
		SDL_FreeSurface(tempSurface);
		return tex;
	}
}

SDL_Texture* DrawController::loadFont(std::string font) 
{
	if (textures.count(font))
	{
		return textures.find(font)->second;
	}

}

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

