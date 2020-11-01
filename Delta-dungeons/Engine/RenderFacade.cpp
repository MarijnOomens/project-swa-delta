#include "RenderFacade.h"

std::string RenderFacade::constructorError() const noexcept
{
	return "SDLFacade constructor is not called";
}

SDL_Texture* RenderFacade::loadTexture(const std::string* path)
{
	return RenderFacade::drawController->loadTexture(path->c_str());
}

RenderFacade::RenderFacade()
{
	RenderFacade::frameManager = std::make_shared<FrameManager>();
	RenderFacade::renderer = std::make_shared<Renderer>();
	RenderFacade::drawController = std::make_shared<DrawController>(renderer);
}

RenderFacade::~RenderFacade() {}

void RenderFacade::setFrameStart()
{
	RenderFacade::frameManager->setFrameStart();
}

void RenderFacade::setFrameDelay()
{
	RenderFacade::frameManager->setFrameDelay();
}

void RenderFacade::drawTexture(std::string path, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimensions, int row, int frames, int speed, bool animated, bool flipped)
{
	Vector2D size;
	SDL_Rect source;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	SDL_Texture* texture = drawController->loadTexture(path);

	if (flipped)
		flip = SDL_FLIP_HORIZONTAL;

	source.w = sourceDimensions.x; 
	source.h = sourceDimensions.y; 
	source.x = coordinates.x;
	source.y = coordinates.y;

	if (animated)
	{
		source.x = source.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		source.y = row * source.h;
	}

	SDL_Rect destination;
	destination.x = transform.position.x; 
	destination.y = transform.position.y; 
	destination.w = sourceDimensions.x * transform.scale.x; 
	destination.h = sourceDimensions.y * transform.scale.y; 

	RenderFacade::drawController->drawTexture(texture, source, destination, flip);
}

void RenderFacade::init(const char* title, const int width, const int height, const bool fullscreen)
{
	RenderFacade::renderer->init(title, width, height, fullscreen);
}

void RenderFacade::render(std::vector<std::shared_ptr<GameObject>> gameObjects)
{
	RenderFacade::renderer->render(gameObjects);
}

void RenderFacade::update(std::vector<GameObject> gameObjects) {}

void RenderFacade::clean()
{
	RenderFacade::renderer->clean();
}

void RenderFacade::beforeFrame()
{
	RenderFacade::renderer->beforeFrame();
}

void RenderFacade::afterFrame()
{
	RenderFacade::renderer->afterFrame();
}

void RenderFacade::passPlayerPosition(int x, int y)
{
	RenderFacade::renderer->updateCamera(x, y);
}
