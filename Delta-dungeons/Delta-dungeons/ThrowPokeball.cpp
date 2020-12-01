#include "ThrowPokeball.h"

ThrowPokeball::ThrowPokeball(const cbSentPokemon f, void* p) : func(f) , pointer(p)
{
	this->transform.position = { -10, -10 };
	this->transform.scale.multiply({ 4, 4 });
	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);
	gc->imageDimensions = { 32, 32 };
	gc->transform = transform;
	gc->isScreen = false;

	stp = std::make_shared<StopStrategy>();
	cc = std::make_shared<CollidingComponent>(stp);
	cc->tag = "pokeball";
	cc->transform.position = this->transform.position;
	
	gc->setTexture("pokeball");

	//textures.try_emplace(name, "Assets/Equipment/" + name + ".png");

	this->components.emplace_back(gc);
	this->components.emplace_back(cc);
}

void ThrowPokeball::interact(std::shared_ptr<BehaviourObject> interactor) {}

void ThrowPokeball::moveUp(int x, int y) {
	updateTransform(x, y);
	isMoving = true;
	direction = "up";
}

void ThrowPokeball::moveDown(int x, int y) {
	updateTransform(x, y);
	isMoving = true;
	direction = "down";
}

void ThrowPokeball::moveLeft(int x, int y) {
	updateTransform(x, y);
	isMoving = true;
	direction = "left";
}

void ThrowPokeball::moveRight(int x, int y) {
	updateTransform(x, y);
	isMoving = true;
	direction = "right";
}

void ThrowPokeball::use() {}

void ThrowPokeball::update() {
	if (isMoving) {
		if (direction == "up") {
			updateTransform(transform.position.x, transform.position.y - 16);
			//checkCollisionboi
		} else 	if (direction == "down") {
			updateTransform(transform.position.x, transform.position.y + 16);
		} else if (direction == "left") {
			updateTransform(transform.position.x - 16, transform.position.y);
		} else if (direction == "right") {
			updateTransform(transform.position.x + 16, transform.position.y);
		}
	}
}

void ThrowPokeball::updateTransform(int x, int y) {
	this->transform.position = { x, y };
	gc->transform = transform;
	cc->transform = transform;
}

void ThrowPokeball::setParent() {}