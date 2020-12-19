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

void Pokemon::catchPokemon () 
{
	AudioUtilities::getInstance().playEffect("caught");
	this->transform.position = { -10, -10 };
	gc->transform = transform;
	cc->transform = transform;
	SceneModifier::getInstance().deleteColliderFromScene(cc);
}

void Pokemon::setParent() 
{
	cc->parent = shared_from_this();
}
