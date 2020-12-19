#pragma once

#include "IInteractiveObject.h"
#include "Player.h"
#include "GraphicsComponent.h"
#include "BoulderPuzzleObject.h"

#include <string>

typedef void(*cbTriggerCollision) (void*);

class BoulderTriggerPuzzleObject : public IInteractiveObject
{
public:
	bool triggered = false;
	std::shared_ptr<BehaviourObject> sharedFromThis;

	BoulderTriggerPuzzleObject() {}
	~BoulderTriggerPuzzleObject() {}

	BoulderTriggerPuzzleObject(int x, int y, const std::string& texture);

	void setBoulderTriggerCallback(cbTriggerCollision triggerCB, void* p);

	void handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void setParent() override;
	void start() override;

	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) override {}
	void update(int time) override {}

private:
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;

	cbTriggerCollision tFunc;
	void* pointer;
};