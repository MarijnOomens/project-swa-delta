#pragma once
#include "IEquipment.h"
#include "Graphicscomponent.h"
#include "ColliderComponent.h"
typedef void(*cbEquipment) (void*, bool);

class RunningShoes : public IEquipment
{
public:
	RunningShoes() {}
	RunningShoes(const cbEquipment f, void* p);
	RunningShoes(int x, int y, std::string texture);
	~RunningShoes() {}

	void use() override;
	void interact() override;
private:
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<ColliderComponent> cc;
	cbEquipment func;
	void* pointer;
	bool isActivated = false;
};