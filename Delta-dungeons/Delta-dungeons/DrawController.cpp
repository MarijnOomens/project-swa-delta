#include "DrawController.h"


SDL_Texture* DrawController::loadTexture(const char* path) {
	SDL_Surface* tempSurface = IMG_Load(path);
	if (!tempSurface) {
		std::cout << "Image not loaded in!" << std::endl;
	}
	else {
		std::cout << "Image is loaded and created!" << std::endl;
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Renderer::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
};

void DrawController::drawTexture(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination) {
	SDL_RenderCopyEx(Renderer::renderer, texture, source, destination, NULL, NULL, SDL_FLIP_NONE);
}

