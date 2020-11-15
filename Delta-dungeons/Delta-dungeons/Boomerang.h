#pragma once

#include "IEquipment.h"
#include <iostream>
#include "GraphicsComponent.h"
#include "ColliderComponent.h"

class Boomerang : public IEquipment
{
public:
	Boomerang() {}
	Boomerang(int x, int y, std::string texture);
	~Boomerang() {}
	
	void use() override;
	void interact() override;

private:
	bool isActivated;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<ColliderComponent> cc;
};