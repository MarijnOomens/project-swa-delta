#include "TriggerPuzzleObject.h"

TriggerPuzzleObject::TriggerPuzzleObject(const cbTriggerCollision cbT, void* p, int x, int y, const std::string& texture) : tFunc(cbT), tPointer(p)
{
	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("pokeball");

	gc->imageDimensions = { 32, 32 };
	gc->transform = transform;
	gc->isScreen = false;

	//stp = std::make_shared<StopStrategy>();
	//cc = std::make_shared<CollidingComponent>(stp);
	//cc->tag = "boulder";
	//cc->transform.position = this->transform.position;

	this->components.emplace_back(gc);
	//this->components.emplace_back(cc);
}

void TriggerPuzzleObject::interact(std::shared_ptr<BehaviourObject> interactor) {
	auto object = dynamic_cast<BoulderPuzzleObject*>(interactor.get());
	if (object != nullptr) {
		tFunc(tPointer, object->transform.position.x, object->transform.position.y);
	}
}

void TriggerPuzzleObject::updateTransform(int x, int y) {
	this->transform.position = { x, y };
	gc->transform = transform;
}

void TriggerPuzzleObject::setParent() {}

void TriggerPuzzleObject::registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger, bool isPuzzleEntrance, bool isPuzzleExit) {}

void TriggerPuzzleObject::update() {}