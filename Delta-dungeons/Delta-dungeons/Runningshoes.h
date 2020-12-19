#pragma once
#include "IEquipment.h"
#include "Graphicscomponent.h"
#include "CollidingComponent.h"
#include "StopStrategy.h"

typedef void(*cbEquipment) (void*, bool);

class RunningShoes : public IEquipment
{
public:
	RunningShoes(const cbEquipment f, void* p, const std::string& t);
	RunningShoes(int x, int y, std::string texture);

	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void use() override;
	void setParent() override;
	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)override {}
	void update() override {}
	void start()override {}
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) override {}
private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;
	cbEquipment func;
	void* pointer;
	bool isActivated = false;
};