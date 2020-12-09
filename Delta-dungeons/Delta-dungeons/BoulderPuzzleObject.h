#pragma once

#include "IInteractiveObject.h"
#include "Player.h"
#include <string>
#include <GraphicsComponent.h>

typedef void(*cbPushCollision) (void*, int, int);

class BoulderPuzzleObject : public IInteractiveObject
{
public:
	BoulderPuzzleObject() {}
	~BoulderPuzzleObject() {}

	BoulderPuzzleObject(const cbPushCollision, void* p, int x, int y, const std::string& texture);
	cbPushCollision pFunc;
	void* pPointer;

	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void setParent() override;
	void update() override;
	void updateTransform(int x, int y);

	bool isMoving = false;

	//interact add the direction
	//directions decides if either x or y gets adjusted
	//call checkcollsion(cc);
	//if hasmoved = true
		// dont move
	//else 
		//call move method within puzzleobject
		//call func method of puzzle.cpp
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger, bool isPuzzleEntrance, bool isPuzzleExit) override;
	void move(KeyCodes direction);

private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;
};