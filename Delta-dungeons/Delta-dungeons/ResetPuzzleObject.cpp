#include "ResetPuzzleObject.h"

ResetPuzzleObject::ResetPuzzleObject(int x, int y, const std::string& texture)
{
	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);

	gc->imageDimensions = { 32, 32 };
	gc->transform = transform;
	gc->isScreen = false;

	stp = std::make_shared<StopStrategy>();
	cc = std::make_shared<CollidingComponent>(stp);
	cc->tag = "door";
	cc->transform.position = this->transform.position;

	this->components.emplace_back(gc);
	this->components.emplace_back(cc);
}

void ResetPuzzleObject::setResetTriggerCallback(cbResetTrigger resetCb, void* p)
{
	this->rFunc = resetCb;
	this->pointer = p;
}

void ResetPuzzleObject::handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void ResetPuzzleObject::interact(std::shared_ptr<BehaviourObject> interactor)
{
	rFunc(pointer);
}

void ResetPuzzleObject::registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) {}

void ResetPuzzleObject::setParent()
{
	orderPuzzleObject = shared_from_this();
}

void ResetPuzzleObject::start() {}


void ResetPuzzleObject::update() {}