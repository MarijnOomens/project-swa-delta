#include "RenderFacade.h"
RenderFacade::~RenderFacade() {}

std::string RenderFacade::constructorError() const noexcept {
	return "SDLFacade constructor is not called";
}

RenderFacade::RenderFacade() {
	RenderFacade::frameManager = std::make_shared<FrameManager>();
	RenderFacade::renderer = std::make_shared<Renderer>();
	RenderFacade::drawController = std::make_shared<DrawController>(renderer);
}

void RenderFacade::init(const char* title, const int width, const int height, const bool fullscreen) {
	RenderFacade::renderer->init(title, width, height, fullscreen);
}

void RenderFacade::setFrameStart() {
	RenderFacade::frameManager->setFrameStart();
}

void RenderFacade::setFrameDelay() {
	RenderFacade::frameManager->setFrameDelay();
}

void RenderFacade::render(std::list<std::shared_ptr<GameObject>> gameObjects) {
	RenderFacade::renderer->render(gameObjects);
}

void RenderFacade::clean() {
	RenderFacade::renderer->clean();
}

SDL_Texture* RenderFacade::loadTexture(const std::string* path) {
	return RenderFacade::drawController->loadTexture(path->c_str());
}
void RenderFacade::drawTexture(const char* path, const Vector2D& source2D, const Vector2D& destination2D) {

}

void RenderFacade::beforeFrame() {
	RenderFacade::renderer->beforeFrame();
}

void RenderFacade::afterFrame() {
	RenderFacade::renderer->afterFrame();
}