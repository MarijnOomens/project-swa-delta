#pragma once
#include "IEquipment.h"
#include "Graphicscomponent.h"
#include "CollidingComponent.h"
#include "StopStrategy.h"

typedef void(*cbEquipment) (void*, bool);

class RunningShoes : public IEquipment
{
public:
	RunningShoes(const cbEquipment f, void* p, const std::string& t);
	RunningShoes(int x, int y, std::string texture);

	void interact() override;
	void use() override;
private:
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;
	cbEquipment func;
	void* pointer;
	bool isActivated = false;
};