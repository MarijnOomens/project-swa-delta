#pragma once

#include "IEquipment.h"
#include <iostream>

class Boomerang : public IEquipment
{
public:
	Boomerang(const std::string& texture);
	void use() override;

private:
	bool isActivated;
};