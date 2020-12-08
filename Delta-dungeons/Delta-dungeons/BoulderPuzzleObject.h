#pragma once

#include "IInteractiveObject.h"
#include <string>
#include <GraphicsComponent.h>


class BoulderPuzzleObject : IInteractiveObject
{
	BoulderPuzzleObject() {}
	~BoulderPuzzleObject() {}

	BoulderPuzzleObject(int x, int y, const std::string& texture, const std::vector<std::string> d);

	void interact(std::shared_ptr<BehaviourObject> interactor) override;

	//interact add the direction
	//directions decides if either x or y gets adjusted
	//call checkcollsion(cc);
	//if hasmoved = true
		// dont move
	//else 
		//call move method within puzzleobject
		//call func method of puzzle.cpp
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger, bool isPuzzleEntrance, bool isPuzzleExit) override;
	void setParent() override;

private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
};