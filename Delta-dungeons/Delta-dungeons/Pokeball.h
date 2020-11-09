#pragma once
#include "IEquipment.h"
#include "GraphicsComponent.h"

class Pokeball : IEquipment
{
public:
	Pokeball();
	Pokeball(int x, int y, int xImage, bool collider, int tileId);
	Pokeball(int x, int y, int yImage, int xImage, bool collider, int tileId);
	~Pokeball();

	std::shared_ptr<GraphicsComponent> gc;

	void use() override;
	void updatePositions(int x, int y) override;
private:
};