#pragma once

#include <iostream>
#include "IEquipment.h"
#include "GraphicsComponent.h"
#include "CollidingComponent.h"
#include "StopStrategy.h"
#include "Player.h"

class Pokeball : public IEquipment
{
public:
	Pokeball(int x, int y, std::string texture);

	void setParent() override;
	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)override {}
	void start()override {}
	void update() override {}
	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void use() override {}
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) override {}

private:
	void* pointer;
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;
};