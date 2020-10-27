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

void DrawController::drawTexture(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination)
{
	try {
		if (renderer.get()->sdlRenderer == NULL) {
			throw("Renderer is NULL!");
		}
		else if (texture == NULL) {
			throw("SDL_Texture is NULL!");
		}
		SDL_RenderCopyEx(renderer.get()->sdlRenderer, texture, &source, &destination, NULL, NULL, SDL_FLIP_NONE);
	}
	catch (std::string error) {
		std::cout << "Error: " << error << std::endl;
	}
}