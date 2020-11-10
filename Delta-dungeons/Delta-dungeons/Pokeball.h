#pragma once
#include "IEquipment.h"
#include "GraphicsComponent.h"

class Pokeball : public IEquipment
{

public:
	int originX;
	int originY;
	bool isCollider;
	std::shared_ptr<GraphicsComponent> gc;

	Pokeball();
	Pokeball(int x, int y, int xImage, bool collider, int tileId);
	Pokeball(int x, int y, int yImage, int xImage, bool collider, int tileId);
	~Pokeball();

	void addGraphicsComponent(std::string imageName);
	void use() override;
private:
};