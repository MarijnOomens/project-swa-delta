#include "Pokemon.h"

const int animationSpeed = 100;

Pokemon::Pokemon(int x, int y, std::string texture)
{
	this->transform.position = { x, y };
	this->transform.scale.multiply({ 4, 4 });
	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);
	gc->imageDimensions = { 32, 32 };
	gc.get()->transform = this->transform;
	gc->playAnimation(0, 3, animationSpeed, false);

	this->components.emplace_back(gc);
}

Pokemon::~Pokemon() {}

void Pokemon::interact() {}

void Pokemon::updatePositions(int x, int y)
{
	this->transform.position.x = this->transform.position.x - x;
	this->transform.position.y = this->transform.position.y - y;
	gc.get()->transform = transform;
}