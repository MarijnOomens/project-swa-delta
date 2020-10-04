#include "DrawController.h"

DrawController::DrawController() {
	texture = new Texture();
}

SDL_Texture* DrawController::loadTexture(const char* path) {
	return texture->LoadTexture(path);
};

void DrawController::drawTexture(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination) {
	SDL_RenderCopyEx(Renderer::renderer, texture, source, destination, NULL, NULL, SDL_FLIP_NONE);
}

