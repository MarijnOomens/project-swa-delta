#pragma once

#include "IEquipment.h"
#include <iostream>
#include "GraphicsComponent.h"
#include "RegularColliderComponent.h"
typedef void(*cbEquipmentBoomerang) (void*, bool);

class Boomerang : public IEquipment
{
public:
	Boomerang(const std::string& t,const cbEquipmentBoomerang f, void* p);
	Boomerang(int x, int y, std::string texture);
	
	void use() override;
	void interact() override;

private:
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<RegularColliderComponent> cc;
	cbEquipmentBoomerang func;
	void* pointer;
	bool isActivated = false;
};