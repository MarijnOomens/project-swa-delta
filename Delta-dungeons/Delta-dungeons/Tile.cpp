#include "Tile.h"


Tile::Tile(){}

Tile::Tile(int x, int y, int xImage) 
{
	transform.position.x = x * 32;
	transform.position.y = y * 32;
	imageCoordinates = Vector2D(xImage * 32, 0);
}

Tile::Tile(int x, int y, int yImage, int xImage) 
{
	transform.position.x = x*32;
	transform.position.y = y*32;
	imageCoordinates = Vector2D(xImage*32,yImage*32);
}

void Tile::addGraphicsComponent(std::shared_ptr<GraphicsComponent>& graphicsComnponent, std::string name) 
{
	gc = graphicsComnponent;
	gc.get()->transform = transform;
	gc.get()->imageCoordinates = imageCoordinates;
	gc.get()->setTexture(name);
}

void Tile::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) {};
void Tile::callbackFunction() {};
void Tile::connectCallback() {};
void Tile::update() {};