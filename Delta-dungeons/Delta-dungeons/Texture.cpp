#include "Texture.h"
#include <iostream>

SDL_Texture* Texture::LoadTexture(const char* texture) {
	SDL_Surface* tempSurface = IMG_Load(texture);
	if (!tempSurface) {
		std::cout << "Image not loaded in!" << std::endl;
	}
	else {
		std::cout << "Image is loaded and created!" << std::endl;
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}