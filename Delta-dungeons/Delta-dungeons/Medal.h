#pragma once
#include "IEquipment.h"
#include "StopStrategy.h"
class Medal : public IEquipment
{
public:
	Medal(int x, int y, std::string texture);

	void interact(std::shared_ptr<BehaviourObject> parent) override;
	void use() override;
	void setParent() override;
	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void start() override;
	void update() override;
private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;
};

