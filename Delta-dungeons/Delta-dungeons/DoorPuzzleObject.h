#pragma once
#include "IInteractiveObject.h"
#include "Player.h"
#include <string>
#include <GraphicsComponent.h>

typedef void(*cbTriggerCollision) (void*);

class DoorPuzzleObject : public IInteractiveObject
{
public:
	DoorPuzzleObject() {}
	~DoorPuzzleObject() {}

	DoorPuzzleObject(int x, int y, const std::string& texture);

	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void setParent() override;
	void update() override;
	void updateTransform(int x, int y);

	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger, bool isPuzzleEntrance, bool isPuzzleExit) override;

private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;
};