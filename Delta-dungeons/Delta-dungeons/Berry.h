#pragma once

#include "IEquipment.h"
#include "GraphicsComponent.h"
#include "ColliderComponent.h"

class Berry : public IEquipment
{
public:
	Berry() {}
	Berry(int x, int y, std::string texture);
	~Berry() {}

	void interact() override;
	void use() override;
private:
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<ColliderComponent> cc;
};