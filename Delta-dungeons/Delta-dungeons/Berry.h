#pragma once

#include "IEquipment.h"
#include "GraphicsComponent.h"
#include "CollidingComponent.h"
#include "StopStrategy.h"
#include "Player.h"
class Berry : public IEquipment
{
public:
	Berry(int x, int y, std::string texture);


	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void use() override;
	void setParent() override;
	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)override;
	void update() override;
	void start()override;

private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;
};