#include "SDLFacade.h"
SDLFacade::~SDLFacade() {}

SDLFacade::SDLFacade() {
	SDLFacade::drawController = new DrawController();
	SDLFacade::frameManager = new FrameManager();
	SDLFacade::renderer = new Renderer();
}

void SDLFacade::setFrameStart() {
	SDLFacade::frameManager->setFrameStart();
}

void SDLFacade::setFrameDelay() {
	SDLFacade::frameManager->setFrameDelay();
}

void SDLFacade::clean() {
	SDLFacade::renderer->clean();
}

SDL_Texture* SDLFacade::loadTexture(const char* path) {
	return SDLFacade::drawController->loadTexture(path);
}
void SDLFacade::drawTexture(const char* path, Vector2D source2D, Vector2D destination2D) {

	SDL_Rect* source = new SDL_Rect();
	source->x = static_cast<int>(source2D.x);
	source->y = static_cast<int>(source2D.y);

	SDL_Rect* destination = new SDL_Rect();
	destination->x = static_cast<int>(destination2D.x);
	destination->y = static_cast<int>(destination2D.y);

	return SDLFacade::drawController->drawTexture(SDLFacade::drawController->loadTexture(path), source, destination);
}