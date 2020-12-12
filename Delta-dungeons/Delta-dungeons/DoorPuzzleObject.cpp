#include "DoorPuzzleObject.h"

DoorPuzzleObject::DoorPuzzleObject(int x, int y, const std::string& texture)
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

void DoorPuzzleObject::handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void DoorPuzzleObject::interact(std::shared_ptr<BehaviourObject> interactor) {
	if (interactor == nullptr) {
		//gc->setTexture("pikachu");
		SceneModifier::getInstance().deleteObjectFromScene(gc);
		SceneModifier::getInstance().deleteColliderFromScene(cc);
	}
}

void DoorPuzzleObject::updateTransform(int x, int y) {}

void DoorPuzzleObject::setParent() {}

void DoorPuzzleObject::start() {}

void DoorPuzzleObject::registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger, bool isPuzzleEntrance, bool isPuzzleExit) {}

void DoorPuzzleObject::update() {}