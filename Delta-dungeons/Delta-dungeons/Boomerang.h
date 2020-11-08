#pragma once

#include "IEquipment.h"

class Boomerang : public IEquipment
{
public:
	void use() override;
	void updatePositions(int x, int y) override;
private:
	bool isActivated;
};