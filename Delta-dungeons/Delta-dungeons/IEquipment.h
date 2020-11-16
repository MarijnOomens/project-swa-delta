#pragma once
#include <string>

class IEquipment
{
public:
	std::string texturePath;
	virtual void use() = 0;
};