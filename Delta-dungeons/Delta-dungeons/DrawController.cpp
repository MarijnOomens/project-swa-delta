#include "DrawController.h"
#include "Renderer.h"

void DrawController::drawTexture(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination) {
	SDL_RenderCopyEx(Renderer::renderer, texture, &source, &destination, NULL, NULL);
}