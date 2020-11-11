#pragma once
#include "IEquipment.h"
#include "Graphicscomponent.h"

class RunningShoes : public IEquipment
{
public:
	std::shared_ptr<GraphicsComponent> gc;
	RunningShoes();
	RunningShoes(int x, int y, std::string texture);
	~RunningShoes();
	void use() override;

private:
};