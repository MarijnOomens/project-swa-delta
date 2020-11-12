#pragma once

#include "IEquipment.h"
#include <iostream>

class Boomerang : public IEquipment
{
public:
	void use() override;

private:
	bool isActivated;
};