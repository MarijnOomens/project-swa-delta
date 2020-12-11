#include "BoulderTriggerPuzzleObject.h"

BoulderTriggerPuzzleObject::BoulderTriggerPuzzleObject(const cbTriggerCollision cbT, void* p, int x, int y, const std::string& texture) : tFunc(cbT), pointer(p)
{
	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("pokeball");

	gc->imageDimensions = { 32, 32 };
	gc->transform = transform;
	gc->isScreen = false;

	this->components.emplace_back(gc);
}

void BoulderTriggerPuzzleObject::handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void BoulderTriggerPuzzleObject::interact(std::shared_ptr<BehaviourObject> interactor) {
	auto object = dynamic_cast<BoulderPuzzleObject*>(interactor.get());
	if (object != nullptr) {
		triggered = true;
		tFunc(pointer);
	}
}

void BoulderTriggerPuzzleObject::updateTransform(int x, int y) {
	this->transform.position = { x, y };
	gc->transform = transform;
}

void BoulderTriggerPuzzleObject::setParent() {}

void BoulderTriggerPuzzleObject::start() {}

void BoulderTriggerPuzzleObject::registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger, bool isPuzzleEntrance, bool isPuzzleExit) {}

void BoulderTriggerPuzzleObject::update() {}