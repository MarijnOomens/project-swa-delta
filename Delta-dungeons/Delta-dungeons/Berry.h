#pragma once

#include "IEquipment.h"
#include "GraphicsComponent.h"

class Berry : public IEquipment
{
public:
	bool isCollider;
	std::shared_ptr<GraphicsComponent> gc;

	Berry();
	Berry(int x, int y, std::string texture);
	~Berry();

	void addGraphicsComponent(std::string imageName);
	void use() override;
private:
	int catchChanceIncrease;
};