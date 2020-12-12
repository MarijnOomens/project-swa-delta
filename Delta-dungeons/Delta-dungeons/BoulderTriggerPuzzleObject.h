#pragma once
#include "IInteractiveObject.h"
#include "Player.h"
#include <string>
#include <GraphicsComponent.h>
#include "BoulderPuzzleObject.h"

typedef void(*cbTriggerCollision) (void*);

class BoulderTriggerPuzzleObject : public IInteractiveObject
{
public:
	cbTriggerCollision tFunc;
	void* pointer;

	bool triggered = false;

	BoulderTriggerPuzzleObject() {}
	~BoulderTriggerPuzzleObject() {}

	BoulderTriggerPuzzleObject(int x, int y, const std::string& texture);

	void setBoulderTriggerCallback(cbTriggerCollision triggerCB, void* p);

	void handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger, bool isPuzzleEntrance, bool isPuzzleExit) override;
	void setParent() override;
	void start() override;
	void update() override;

	void updateTransform(int x, int y);


private:
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;

};