#pragma once
#include "IInteractiveObject.h"
#include "Player.h"
#include <string>
#include <GraphicsComponent.h>

typedef void(*cbOrderTrigger) (void*, int);

class OrderTriggerPuzzleObject : public IInteractiveObject
{
public:
	cbOrderTrigger oFunc;
	void* pointer;

	bool triggered = false;
	int orderNumber = 0;

	OrderTriggerPuzzleObject() {}
	~OrderTriggerPuzzleObject() {}

	OrderTriggerPuzzleObject(const cbOrderTrigger, void* p, int orderNumber, int x, int y, const std::string& texture);

	void handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger, bool isPuzzleEntrance, bool isPuzzleExit) override;
	void setParent() override;
	void start() override;
	void update() override;

	void updateTransform(int x, int y);


private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;

};