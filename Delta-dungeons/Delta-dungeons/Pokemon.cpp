#include "Pokemon.h"

const int animationSpeed = 120;

Pokemon::Pokemon(int x, int y, std::string &texture)
{
	this->transform.position = { x, y };
	this->transform.scale.multiply({ 4, 4 });
	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);
	gc->imageDimensions = { 32, 32 };
	gc->transform = this->transform;
	gc->playAnimation(0, 3, animationSpeed, false);
	gc->isScreen = false;
	this->components.emplace_back(gc);
}

void Pokemon::interact() {}