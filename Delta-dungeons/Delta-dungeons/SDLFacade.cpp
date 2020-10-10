#include "SDLFacade.h"
SDLFacade::~SDLFacade() {}

std::string SDLFacade::constructorError() const noexcept {
	return "SDLFacade constructor is not called";
}

SDLFacade::SDLFacade() {
	SDLFacade::drawController = std::make_shared<DrawController>();
	SDLFacade::frameManager = std::make_shared<FrameManager>();
	SDLFacade::renderer = std::make_shared<Renderer>();
}

void SDLFacade::initRenderer(const char* title, const int width, const int height, const bool fullscreen) {
	SDLFacade::renderer->init(title, width, height, fullscreen);
}

void SDLFacade::setFrameStart() {
	SDLFacade::frameManager->setFrameStart();
}

void SDLFacade::setFrameDelay() {
	SDLFacade::frameManager->setFrameDelay();
}

void SDLFacade::render(std::list<std::shared_ptr<GameObject>> gameObjects) {
	SDLFacade::renderer->render(gameObjects);
}

void SDLFacade::clean() {
	SDLFacade::renderer->clean();
}

SDL_Texture* SDLFacade::loadTexture(const std::string* path) {
	return SDLFacade::drawController->loadTexture(path->c_str());
}
void SDLFacade::drawTexture(const char* path, const Vector2D source2D, const Vector2D destination2D) {

	SDL_Rect* source = new SDL_Rect();
	source->x = static_cast<int>(source2D.x);
	source->y = static_cast<int>(source2D.y);

	SDL_Rect* destination = new SDL_Rect();
	destination->x = static_cast<int>(destination2D.x);
	destination->y = static_cast<int>(destination2D.y);

	return SDLFacade::drawController->drawTexture(SDLFacade::drawController->loadTexture(path), source, destination);
}