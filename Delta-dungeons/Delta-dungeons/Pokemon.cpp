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
	this->transform.position = { -10, -10 };
	gc->transform = transform;
	cc->transform = transform;
	SceneModifier::getInstance().deleteColliderFromScene(cc);
}

void Pokemon::setParent() 
{
	cc->parent = shared_from_this();
}

void Pokemon::update(int time)
{
	if ((time - previoustime) >= 3000)
	{
		previoustime = time;
		walk();
	}
}

void Pokemon::walk()
{
	int randomDirection = rand() % 3;
	playAnimation(randomDirection);
	switch (randomDirection)
	{
	case 0:
		transform.position.y += 32;
		break;
	case 1:
		transform.position.y -= 32;
		break;
	case 2:
		transform.position.x += 32;
		break;
	case 3:
		transform.position.x -= 32;
		break;
	default:
		break;
	}
	gc->transform.position = transform.position;
}

void Pokemon::playAnimation(int direction) 
{
	switch (direction)
	{
	case 0:
		gc->playAnimation(0, 3, animationSpeed, false);
		break;
	case 1:
		gc->playAnimation(1, 3, animationSpeed, false);
		break;
	case 2:
		gc->playAnimation(2, 3, animationSpeed, true);
		break;
	case 3:
		gc->playAnimation(2, 3, animationSpeed, false);
		break;
	default:
		break;
	}
}
