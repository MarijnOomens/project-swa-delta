#include "Pokeball.h"

Pokeball::Pokeball() {}

const int animationSpeed = 0;


Pokeball::Pokeball(int x, int y, int xImage, bool collider, int tileId) {
	this->transform.position = { x, y };
	this->transform.scale.multiply({ 4, 4 });
	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("Level1");
	gc->imageDimensions = { 32, 32 };
	gc.get()->transform = this->transform;
	gc->playAnimation(0, 1, animationSpeed, false);

	this->components.emplace_back(gc);
}

Pokeball::Pokeball(int x, int y, int yImage, int xImage, bool collider, int tileId) {}

Pokeball::~Pokeball() {}

void Pokeball::use() {}

void Pokeball::updatePositions(int x, int y)
{
	this->transform.position.x = this->transform.position.x - x;
	this->transform.position.y = this->transform.position.y - y;
	gc.get()->transform = transform;
}