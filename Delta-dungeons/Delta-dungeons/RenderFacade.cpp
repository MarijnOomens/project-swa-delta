#include "RenderFacade.h"
RenderFacade::~RenderFacade() {}

std::string RenderFacade::constructorError() const noexcept {
	return "SDLFacade constructor is not called";
}

RenderFacade::RenderFacade() {
	RenderFacade::drawController = std::make_shared<DrawController>();
	RenderFacade::frameManager = std::make_shared<FrameManager>();
	RenderFacade::renderer = std::make_shared<Renderer>();
}

void RenderFacade::initRenderer(const char* title, const int width, const int height, const bool fullscreen) {
	RenderFacade::renderer->init(title, width, height, fullscreen);
}

void RenderFacade::setFrameStart() {
	RenderFacade::frameManager->setFrameStart();
}

void RenderFacade::setFrameDelay() {
	RenderFacade::frameManager->setFrameDelay();
}

void RenderFacade::render(std::list<GameObject> gameObjects) {
	RenderFacade::renderer->render(gameObjects);
}

void RenderFacade::clean() {
	RenderFacade::renderer->clean();
}

SDL_Texture* RenderFacade::loadTexture(const std::string* path) {
	return RenderFacade::drawController->loadTexture(path->c_str());
}
void RenderFacade::drawTexture(const char* path, const Vector2D source2D, const Vector2D destination2D) {

	SDL_Rect* source = new SDL_Rect();
	source->x = static_cast<int>(source2D.x);
	source->y = static_cast<int>(source2D.y);

	SDL_Rect* destination = new SDL_Rect();
	destination->x = static_cast<int>(destination2D.x);
	destination->y = static_cast<int>(destination2D.y);

	return RenderFacade::drawController->drawTexture(RenderFacade::drawController->loadTexture(path), source, destination);
}