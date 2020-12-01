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

void ThrowPokeball::use() {
	//based on direction
	//transform.position.y -= baseMovementSpeed;
	this->transform.position = { 1280, 1280 };
	gc->transform = transform;
	cc->transform = transform;
	isMoving = true;
	direction = "right";
	func(pointer);
}

void ThrowPokeball::update() {
	if (isMoving) {
		if (direction == "right") {
			this->transform.position.x += 16;
			gc->transform = transform;
			cc->transform = transform;
		}
	}
}

void ThrowPokeball::setParent() {}