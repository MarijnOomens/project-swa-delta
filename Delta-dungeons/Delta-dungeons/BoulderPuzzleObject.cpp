#include "BoulderPuzzleObject.h"

BoulderPuzzleObject::BoulderPuzzleObject(const cbPushCollision cbP, void* p, cbCollision cbC, void* gP, int x, int y, const std::string& texture) : pFunc(cbP), pPointer(p), cFunc(cbC), gPointer(gP)
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
		move(object->currentDirection);
	}
}

void BoulderPuzzleObject::move(KeyCodes direction) 
{
	currentDirection = direction;
	//if (isMoving) {
		if (direction == KeyCodes::KEY_UP || direction == KeyCodes::KEY_W) {
			cFunc(gPointer, shared_from_this(), transform.position.x, transform.position.y - 128, KeyCodes::KEY_UP, (gc->imageDimensions.x * gc->transform.scale.x));
			if (canPush) {
				pushed = true;
				endY = transform.position.y - 128;
				pFunc(pPointer, transform.position.x, transform.position.y - 128);
			}
			canPush = true;
		}
		else if (direction == KeyCodes::KEY_DOWN || direction == KeyCodes::KEY_S) {
			cFunc(gPointer, shared_from_this(), transform.position.x, transform.position.y + 128, KeyCodes::KEY_DOWN, (gc->imageDimensions.x * gc->transform.scale.x));
			if (canPush) {
				pushed = true;
				endY = transform.position.y + 128;
				pFunc(pPointer, transform.position.x, transform.position.y + 128);
			}
			canPush = true;
		}
		else if (direction == KeyCodes::KEY_LEFT || direction == KeyCodes::KEY_A) {
			cFunc(gPointer, shared_from_this(), this->transform.position.x - 128, this->transform.position.y, KeyCodes::KEY_LEFT, (gc->imageDimensions.x * gc->transform.scale.x));
			if (canPush) {
				pushed = true;
				endX = transform.position.x - 128;
				pFunc(pPointer, transform.position.x - 128, transform.position.y);
			}
			canPush = true;
		}
		else if (direction == KeyCodes::KEY_RIGHT || direction == KeyCodes::KEY_D) {
			cFunc(gPointer, shared_from_this(), this->transform.position.x + 128, this->transform.position.y, KeyCodes::KEY_RIGHT, (gc->imageDimensions.x * gc->transform.scale.x));
			if (canPush) {
				pushed = true;
				endX = transform.position.x + 128;
				pFunc(pPointer, transform.position.x + 128, transform.position.y);
			}
			canPush = true;
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

void BoulderPuzzleObject::registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger, bool isPuzzleEntrance, bool isPuzzleExit) 
{
	std::cout << "Can't push object!" << std::endl;
	canPush = false;
}

void BoulderPuzzleObject::update() 
{
	if (pushed) 
	{
		if (currentDirection == KeyCodes::KEY_DOWN || currentDirection == KeyCodes::KEY_S)
		{
			if (transform.position.y < endY) { updateTransform(transform.position.x, transform.position.y + 8); }
			else { pushed = false; }
		}
		else if (currentDirection == KeyCodes::KEY_UP || currentDirection == KeyCodes::KEY_W)
		{
			if (transform.position.y > endY) { updateTransform(transform.position.x, transform.position.y - 8); }
			else { pushed = false; }
		}
		else if (currentDirection == KeyCodes::KEY_LEFT || currentDirection == KeyCodes::KEY_A)
		{
			if (transform.position.x > endX) { updateTransform(transform.position.x - 8, transform.position.y); }
			else { pushed = false; }
		}
		else if (currentDirection == KeyCodes::KEY_RIGHT || currentDirection == KeyCodes::KEY_D)
		{
			if (transform.position.x < endX) { updateTransform(transform.position.x + 8, transform.position.y); }
			else { pushed = false; }
		}
	}
}