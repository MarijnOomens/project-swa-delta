#include "DrawController.h"

DrawController::DrawController() {};
DrawController::DrawController(std::shared_ptr<Renderer> r)
{
	renderer = r;
};
DrawController::~DrawController() {};

SDL_Texture* DrawController::loadTexture(const char* path) {
	SDL_Surface* tempSurface = IMG_Load(path);
	try {
		if (!tempSurface) {
			throw("Image not loaded in!");
		}
		std::cout << "Image is loaded and created!" << std::endl;
	}
	catch (std::string error) {
		std::cout << "Error: " << error << std::endl;
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer.get()->sdlRenderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return tex;
};

void DrawController::drawTexture(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination) {
	try {
		if (renderer.get()->sdlRenderer == NULL) {
			throw("Renderer is NULL!");
		}
		else if (texture == NULL) {
			throw("SDL_Texture is NULL!");
		}
		SDL_RenderCopyEx(renderer.get()->sdlRenderer, texture, &source, &destination, NULL, NULL, SDL_FLIP_NONE);
		std::cout << "Copy rendered" << std::endl;
	}
	catch (std::string error) {
		std::cout << "Error: " << error << std::endl;
	}
}

