#pragma once

#include "IEquipment.h"
#include "GraphicsComponent.h"
#include "ColliderComponent.h"


class Pokeball : public IEquipment
{
public:
	bool isCollider;

	Pokeball(int x, int y, std::string texture);
	~Pokeball();

	void interact() override;
	void use() override;
private:
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<ColliderComponent> cc;
};