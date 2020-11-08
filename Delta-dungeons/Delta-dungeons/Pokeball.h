#pragma once
#include "IEquipment.h"

class Pokeball : IEquipment
{
public:
	Pokeball();
	Pokeball(int x, int y, int xImage, bool collider, int tileId);
	Pokeball(int x, int y, int yImage, int xImage, bool collider, int tileId);
	~Pokeball();

	void use() override;
private:
};