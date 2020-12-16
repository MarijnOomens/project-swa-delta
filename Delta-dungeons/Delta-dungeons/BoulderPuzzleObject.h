#pragma once

#include "IInteractiveObject.h"
#include "Player.h"
#include "GraphicsComponent.h"

#include <string>

typedef void(*cbInteract) (void*, std::shared_ptr<BehaviourObject>, int, int, int, int);
typedef void(*cbCollision) (void*, std::shared_ptr<CollidingComponent>, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);

class BoulderPuzzleObject : public IInteractiveObject
{
public:
	std::shared_ptr<BehaviourObject> sharedFromThis;

	BoulderPuzzleObject() {}
	~BoulderPuzzleObject() {}

	BoulderPuzzleObject(cbInteract cbI, cbCollision cbC, void* lbP, int x, int y, const std::string& texture);

	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) override;
	void setParent() override;
	void start() override;
	void update() override;

	void handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override {}

	void updateTransform(int x, int y);
	void move(KeyCodes direction);

private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;

	KeyCodes currentDirection;

	cbInteract iFunc;
	cbCollision cFunc;
	void* lbPointer;

	bool canPush = true;
	bool pushed = false;
	int startX = 0;
	int startY = 0;
	int endY = 0;
	int endX = 0;
};