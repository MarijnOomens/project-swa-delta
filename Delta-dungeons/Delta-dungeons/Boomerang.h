#pragma once

#include "IEquipment.h"

class Boomerang : public IEquipment
{
public:
	void use() override;
private:
	bool isActivated;
};