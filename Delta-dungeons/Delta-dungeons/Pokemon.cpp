#include "Pokemon.h"

Pokemon::Pokemon(int x, int y, const std::string& texture, cbCollision collisionCb, void* p, int attackTime): func(collisionCb), pointer(p), attackTime(attackTime)
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

void Pokemon::update(int time)
{
	if ((time - previoustime) >= attackTime)
	{
		previoustime = time;
		walk();
	}
}

void Pokemon::registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger)
{
	hasMoved = true;
}

void Pokemon::walk()
{
	int randomDirection = rand() % 3;
	playAnimation(randomDirection);
	switch (randomDirection)
	{
	case 0:
		func(pointer, cc, shared_from_this(), this->transform.position.x, this->transform.position.y + 32, KeyCodes::KEY_DOWN, (gc->imageDimensions.x * gc->transform.scale.x));
		if (!hasMoved)
		{
			transform.position.y += 32;
		}
		break;
	case 1:
		func(pointer, cc, shared_from_this(), this->transform.position.x, this->transform.position.y -32 , KeyCodes::KEY_UP, (gc->imageDimensions.x * gc->transform.scale.x));
		if (!hasMoved)
		{
			transform.position.y -= 32;
		}
		break;
	case 2:
		func(pointer, cc, shared_from_this(), this->transform.position.x + 32, this->transform.position.y, KeyCodes::KEY_RIGHT, (gc->imageDimensions.x * gc->transform.scale.x));
		if (!hasMoved)
		{
			transform.position.x += 32;
		}
		break;
	case 3:
		func(pointer, cc, shared_from_this(), this->transform.position.x - 32, this->transform.position.y, KeyCodes::KEY_LEFT, (gc->imageDimensions.x * gc->transform.scale.x));
		if (!hasMoved)
		{
			transform.position.x -= 32;
		}
		break;
	default:
		break;
	}
	gc->transform.position = transform.position;
	cc->transform.position = transform.position;
	hasMoved = false;
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
