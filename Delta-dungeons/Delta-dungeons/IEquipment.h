#pragma once
#include <string>

class IEquipment
{
public:
	std::string texture;
	virtual void use() = 0;
};