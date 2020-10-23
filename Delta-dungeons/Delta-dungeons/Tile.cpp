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

void Tile::addGraphicsComponent(GraphicsComponent* graphicsComnponent, std::string name) 
{
	gc = graphicsComnponent;
	gc->transform = transform;
	gc->imageCoordinates = imageCoordinates;
	gc->SetTexture(name);
}

void Tile:: handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) {};
void Tile::callbackFunction() {};
void Tile::connectCallback() {};