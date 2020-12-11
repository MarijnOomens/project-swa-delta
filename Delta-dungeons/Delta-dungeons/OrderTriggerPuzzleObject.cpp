#include "OrderTriggerPuzzleObject.h"

OrderTriggerPuzzleObject::OrderTriggerPuzzleObject(const cbOrderTrigger cbO, void* p, int orderNumber, int x, int y, const std::string& texture) : oFunc(cbO), pointer(p)
{
	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });
	this->orderNumber = orderNumber;

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("pokeball");

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

void OrderTriggerPuzzleObject::handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void OrderTriggerPuzzleObject::interact(std::shared_ptr<BehaviourObject> interactor)
{
	oFunc(pointer, orderNumber);
}

void OrderTriggerPuzzleObject::updateTransform(int x, int y) 
{
	this->transform.position = { x, y };
	gc->transform = transform;
}

void OrderTriggerPuzzleObject::setParent() {}

void OrderTriggerPuzzleObject::start() {}

void OrderTriggerPuzzleObject::registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger, bool isPuzzleEntrance, bool isPuzzleExit) {}

void OrderTriggerPuzzleObject::update() {}