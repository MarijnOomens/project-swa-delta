#pragma once
#include "IInteractiveObject.h"
#include "Player.h"
#include <string>
#include <GraphicsComponent.h>
#include "BoulderPuzzleObject.h"

typedef void(*cbTriggerCollision) (void*, int, int);

class TriggerPuzzleObject : public IInteractiveObject
{
public:
	TriggerPuzzleObject() {}
	~TriggerPuzzleObject() {}

	TriggerPuzzleObject(const cbTriggerCollision, void* p, int x, int y, const std::string& texture);
	cbTriggerCollision tFunc;
	void* tPointer;

	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void setParent() override;
	void update() override;
	void updateTransform(int x, int y);
	bool triggered = false;

	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger, bool isPuzzleEntrance, bool isPuzzleExit) override;

private:
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;
};