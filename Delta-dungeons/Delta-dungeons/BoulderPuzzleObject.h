#pragma once

#include "IInteractiveObject.h"
#include "Player.h"
#include <string>
#include <GraphicsComponent.h>

typedef void(*cbInteract) (void*, std::shared_ptr<BehaviourObject>, int, int);
typedef void(*cbCollision) (void*, std::shared_ptr<CollidingComponent>, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);

class BoulderPuzzleObject : public IInteractiveObject
{
public:
	BoulderPuzzleObject() {}
	~BoulderPuzzleObject() {}

	BoulderPuzzleObject(cbInteract, cbCollision, void* gP, int x, int y, const std::string& texture);
	cbInteract iFunc;
	cbCollision cFunc;
	void* gPointer;

	void handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger, bool isPuzzleEntrance, bool isPuzzleExit) override;
	void setParent() override;
	void start() override;
	void update() override;
	void updateTransform(int x, int y);
	KeyCodes currentDirection;
	bool canPush = true;
	bool pushed = false;
	int endY = 0;
	int endX = 0;

	//interact add the direction
	//directions decides if either x or y gets adjusted
	//call checkcollsion(cc);
	//if hasmoved = true
		// dont move
	//else 
		//call move method within puzzleobject
		//call func method of puzzle.cpp
	void move(KeyCodes direction);

private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;
};