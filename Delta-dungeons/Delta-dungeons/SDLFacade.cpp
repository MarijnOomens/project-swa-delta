#include "SDLFacade.h"
SDLFacade::SDLFacade() {
	drawController = new DrawController();
}

SDL_Texture* SDLFacade::loadTexture(const char* path) {
	return drawController->loadTexture(path);
}
void SDLFacade::drawTexture(const char* path, Vector2D source2D, Vector2D destination2D) {

	SDL_Rect* source = new SDL_Rect();
	source->x = source2D.x;
	source->y = source2D.y;

	SDL_Rect* destination = new SDL_Rect();
	destination->x = destination2D.x;
	destination->y = destination2D.y;

	return drawController->drawTexture(drawController->loadTexture(path), source, destination);
}