#pragma once
#include "IInteractiveObject.h"
#include "Player.h"
#include <string>
#include <GraphicsComponent.h>
#include "BoulderPuzzleObject.h"

typedef void(*cbTriggerCollision) (void*);

class TriggerPuzzleObject : public IInteractiveObject
{
public:
	TriggerPuzzleObject() {}
	~TriggerPuzzleObject() {}

	TriggerPuzzleObject(const cbTriggerCollision, void* p, int x, int y, const std::string& texture);
	cbTriggerCollision tFunc;
	void* tPointer;

	void handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger, bool isPuzzleEntrance, bool isPuzzleExit) override;
	void setParent() override;
	void start() override;
	void update() override;

	void updateTransform(int x, int y);
	bool triggered = false;


private:
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;
};