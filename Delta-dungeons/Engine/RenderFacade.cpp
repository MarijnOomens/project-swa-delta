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

void RenderFacade::drawTexture(std::string path, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimensions)
{
	Vector2D size;
	SDL_Rect source;
	source.x = coordinates.x;	// Moet 0 zijn om de volledige texture te tekenen, omdat de source rectangle aangeeft welk deel van de texture wordt getekend. Dus als dit 32 is, wordt x positie 32 + width
	source.y = coordinates.y;	// getekend en dat kan niet met een 32 x 32 texture. Dan wordt als het ware de 'data' buiten de texture getekend, terwijl daar niets zit.
	source.w = sourceDimensions.x; // Moet eigenlijk width en height zijn, maar 'Vector2D' heeft alleen x en y variabelen.
	source.h = sourceDimensions.y; //
	SDL_Texture* texture = drawController->loadTexture(path);

	SDL_Rect destination;
	destination.x = transform.position.x; // Locatie waar je de texture wilt tekenen.
	destination.y = transform.position.y; //
	destination.w = sourceDimensions.x * transform.scale.x; // Moet eigenlijk width en height zijn, maar 'Vector2D' heeft alleen x en y variabelen.
	destination.h = sourceDimensions.y * transform.scale.y; //

	RenderFacade::drawController->drawTexture(texture, source, destination);
}

void RenderFacade::drawText(std::string path, std::string text, Colour colour, const Transform& transform) 
{

}

void RenderFacade::init(const char* title, const int width, const int height, const bool fullscreen)
{
	RenderFacade::renderer->init(title, width, height, fullscreen);
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