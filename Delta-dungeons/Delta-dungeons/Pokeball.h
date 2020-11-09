#pragma once
#include "IEquipment.h"
#include "GraphicsComponent.h"

class Pokeball : public IEquipment
{

public:
	int originX;
	int originY;
	bool isCollider;
	Vector2D imageCoordinates;
	std::shared_ptr<GraphicsComponent> gc;

	Pokeball();
	Pokeball(int x, int y, int xImage, bool collider, int tileId);
	Pokeball(int x, int y, int yImage, int xImage, bool collider, int tileId);
	~Pokeball();

	void addGraphicsComponent(std::string imageName);
	void use() override;
	void updatePositions(int x, int y) override;
private:
};