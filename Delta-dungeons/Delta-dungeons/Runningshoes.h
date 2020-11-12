#pragma once
#include "IEquipment.h"
#include "Graphicscomponent.h"
typedef void(*cbEquipment) (void*, bool);

class RunningShoes : public IEquipment
{
public:
	std::shared_ptr<GraphicsComponent> gc;
	RunningShoes();
	RunningShoes(cbEquipment f, void* p);
	RunningShoes(int x, int y, std::string texture);
	~RunningShoes();
	void use() override;

	cbEquipment func;
	void* pointer;
	bool isActivated = false;
	bool isCollider;

private:
};