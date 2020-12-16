#pragma once

#include "IInteractiveObject.h"
#include "Player.h"
#include "GraphicsComponent.h"

#include <string>

typedef void(*cbOrderTrigger) (void*, int);

class OrderTriggerPuzzleObject : public IInteractiveObject
{
public:
	std::shared_ptr<BehaviourObject> orderPuzzleObject;

	bool triggered = false;
	int orderNumber = 0;

	OrderTriggerPuzzleObject() {}
	~OrderTriggerPuzzleObject() {}

	OrderTriggerPuzzleObject(int x, int y, const std::string& texture, int tileId);

	void setOrderNumber(int tileId);
	void setOrderTriggerCallback(cbOrderTrigger orderCb, void* p);

	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void setParent() override;
	void start() override;

	void handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override {}
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) override {}
	void update() override {}

private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;

	cbOrderTrigger oFunc;
	void* pointer;
};