#pragma once

#include "IEquipment.h"
#include "GraphicsComponent.h"

class Pokeball : public IEquipment
{
public:
	bool isCollider;
	std::shared_ptr<GraphicsComponent> gc;

	Pokeball();
	Pokeball(int x, int y, std::string texture);
	~Pokeball();

	void addGraphicsComponent(std::string imageName);
	void use() override;
private:
};