#pragma once
#include "IEquipment.h"
#include "Graphicscomponent.h"
typedef void(*cbFunction) (void*, const bool);

class RunningShoes : public IEquipment
{
public:
	std::shared_ptr<GraphicsComponent> gc;
	RunningShoes();
	RunningShoes(const cbFunction f, void* p);
	RunningShoes(int x, int y, std::string texture);
	~RunningShoes();
	void use() override;

	cbFunction func;
	void* pointer;
	bool isActivated = false;
	bool isCollider;

private:
};