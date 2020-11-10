#include "Pokeball.h"

Pokeball::Pokeball() {}

// does not get used if the tileMap remains the same order.
Pokeball::Pokeball(int x, int y, int xImage, bool collider, int tileId) {
	originX = x * 128;
	originY = y * 128;

	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });

	isCollider = collider;
	gc = std::make_shared<GraphicsComponent>();

	gc.get()->transform = transform;
	gc.get()->imageCoordinates = Vector2D(xImage * 32, 0);
	gc->setTexture("Level1");
	gc->isScreen = false;
	this->components.emplace_back(gc);
}

Pokeball::Pokeball(int x, int y, int yImage, int xImage, bool collider, int tileId) {
	originX = x * 128;
	originY = y * 128;

	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });

	isCollider = collider;
	gc = std::make_shared<GraphicsComponent>();

	gc.get()->transform = transform;
	gc.get()->imageCoordinates.x = xImage * 32;
	gc.get()->imageCoordinates.y = yImage * 32;
	gc->setTexture("Level1");
	gc->isScreen = false;
	this->components.emplace_back(gc);
}

Pokeball::~Pokeball() {}

void Pokeball::use() {}