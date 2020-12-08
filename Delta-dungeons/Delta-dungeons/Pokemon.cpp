#include "Pokemon.h"

Pokemon::Pokemon(int x, int y, const std::string& texture)
{
	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });
	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);
	gc->imageDimensions = { 32, 32 };
	gc->transform = this->transform;
	gc->playAnimation(0, 3, animationSpeed, false);
	gc->isScreen = false;

	stp = std::make_shared<DamageStrategy>();
	cc = std::make_shared<CollidingComponent>(stp);
	cc->tag = "pokemon";
	cc->transform.position = this->transform.position;

	this->components.emplace_back(gc);
	this->components.emplace_back(cc);
}

void Pokemon::catchPokemon () {

	this->transform.position = { -10, -10 };
	gc->transform = transform;
	cc->transform = transform;

	SceneModifier::getInstance().deleteColliderFromScene(cc);
	
}

void Pokemon::interact(std::shared_ptr<BehaviourObject> interactor) {}

void Pokemon::setParent() {
	cc->parent = shared_from_this();
}

void Pokemon::registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) {

}

void Pokemon::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void Pokemon::update() {}

void Pokemon::start() {}