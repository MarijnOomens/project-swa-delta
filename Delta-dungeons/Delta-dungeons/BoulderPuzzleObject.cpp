#include "BoulderPuzzleObject.h"

BoulderPuzzleObject::BoulderPuzzleObject(const cbPushCollision cbP, void* p, int x, int y, const std::string& texture) : pFunc(cbP), pPointer(p)
{
	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("pokeball");

	gc->imageDimensions = { 32, 32 };
	gc->transform = transform;
	gc->isScreen = false;

	stp = std::make_shared<StopStrategy>();
	cc = std::make_shared<CollidingComponent>(stp);
	cc->tag = "boulder";
	cc->transform.position = this->transform.position;

	this->components.emplace_back(gc);
	this->components.emplace_back(cc);

}

void BoulderPuzzleObject::interact(std::shared_ptr<BehaviourObject> interactor) {
	auto object = dynamic_cast<Player*>(interactor.get());
	if (object != nullptr) {
		std::cout << "Pushed object!" << std::endl;

		move(object->currentDirection);
	}
}

void BoulderPuzzleObject::move(KeyCodes direction) 
{
	//checkCollision
	//if (isMoving) {
		if (direction == KeyCodes::KEY_UP || direction == KeyCodes::KEY_W) {
			updateTransform(transform.position.x, transform.position.y - 128);
			//tFunc(gameMangerPointer, transform.position.x, transform.position.y);
		}
		else if (direction == KeyCodes::KEY_DOWN || direction == KeyCodes::KEY_S) {
			updateTransform(transform.position.x, transform.position.y + 128);
			//tFunc(gameMangerPointer, transform.position.x, transform.position.y);
		}
		else if (direction == KeyCodes::KEY_LEFT || direction == KeyCodes::KEY_A) {
			updateTransform(transform.position.x - 128, transform.position.y);
			//tFunc(gameMangerPointer, transform.position.x, transform.position.y);
		}
		else if (direction == KeyCodes::KEY_RIGHT || direction == KeyCodes::KEY_D) {
			updateTransform(transform.position.x + 128, transform.position.y);
			//tFunc(gameMangerPointer, transform.position.x, transform.position.y);
		}
	//}
}

void BoulderPuzzleObject::updateTransform(int x, int y) {
	this->transform.position = { x, y };
	gc->transform = transform;
	cc->transform = transform;
}

void BoulderPuzzleObject::setParent() {
	cc->parent = shared_from_this();
}

void BoulderPuzzleObject::registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger, bool isPuzzleEntrance, bool isPuzzleExit) {}

void BoulderPuzzleObject::update() {}