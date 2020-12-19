#pragma once

#include "IEquipment.h"
#include <iostream>
#include "GraphicsComponent.h"
#include "CollidingComponent.h"
#include "StopStrategy.h"

typedef void(*cbEquipmentBoomerang) (void*, bool);

class Boomerang : public IEquipment
{
public:
	Boomerang(const std::string& t,const cbEquipmentBoomerang f, void* p);
	Boomerang(int x, int y, std::string texture);
	
	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void use() override;
	void setParent() override;
	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)override {}
	void update(int time) override {}
	void start()override {}
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) override {}

private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;
	cbEquipmentBoomerang func;
	void* pointer;
	bool isActivated = false;
};