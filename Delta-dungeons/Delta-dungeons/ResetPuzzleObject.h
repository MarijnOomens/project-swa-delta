#pragma once

#include "IInteractiveObject.h"
#include "Player.h"
#include "GraphicsComponent.h"

#include <string>

typedef void(*cbResetTrigger) (void*);

class ResetPuzzleObject : public IInteractiveObject
{
public:
	std::shared_ptr<BehaviourObject> orderPuzzleObject;

	ResetPuzzleObject() {}
	~ResetPuzzleObject() {}

	ResetPuzzleObject(int x, int y, const std::string& texture);

	void setResetTriggerCallback(cbResetTrigger orderCb, void* p);

	void handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) override;
	void setParent() override;
	void start() override;
	void update() override;

private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;

	cbResetTrigger rFunc;
	void* pointer;
};