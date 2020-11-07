#include "Tile.h"

Tile::Tile() {}

/// <summary>
/// Grab the image from the first row only of the png
/// </summary>
/// <param name="x">The horizontal placement of tile</param>
/// <param name="y">The vertical placement of tile</param>
/// <param name="xImage">Specific horizontal image location of tile png</param>
Tile::Tile(int x, int y, int xImage, bool collider)
{
	originX = x * 128;
	originY = y * 128;

	this->transform.scale.multiply({ 4, 4 });
	transform.position.x = x * 128;
	transform.position.y = y * 128;
	imageCoordinates = Vector2D(xImage * 32, 0);
}

/// <summary>
/// Grabs the images from the second row and beyond of the png
/// </summary>
/// <param name="x">The horizontal placement of tile</param>
/// <param name="y">The vertical placement of tile</param>
/// <param name="xImage">Horizontal image location of tile png</param>
/// <param name="yImage">Vertical image location of tile png</param>

Tile::Tile(int x, int y, int yImage, int xImage, bool collider)
{
	originX = x * 128;
	originY = y * 128;
	isCollider = collider;
	this->transform.scale.multiply({ 4, 4 });
	transform.position.x = x * 128;
	transform.position.y = y * 128;
	imageCoordinates = Vector2D(xImage * 32, yImage * 32);
}

/// <summary>
/// Add the graphics component and set the tranform-, imagecoordinate- and texture values.
/// </summary>
/// <param name="graphicsComnponent">An clean graphicscomponent without tile information</param>
/// <param name="name">Texture name of the png</param>
void Tile::addGraphicsComponent(std::string name)
{
	gc = std::make_shared<GraphicsComponent>();
	gc.get()->transform = transform;
	gc.get()->imageCoordinates = imageCoordinates;
	gc.get()->setTexture(name);
	this->components.emplace_back(gc);
}

void Tile::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) {}
void Tile::callbackFunction() {}
void Tile::connectCallback() {}

void Tile::update() {}

void Tile::updatePositions(int x, int y)
{
	this->transform.position.x = this->transform.position.x - x;
	this->transform.position.y = this->transform.position.y - y;
	gc.get()->transform = transform;
}