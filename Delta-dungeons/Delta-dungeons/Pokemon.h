#pragma once

#include "InteractiveObject.h"
#include <string>

class Pokemon : InteractiveObject
{
private:
	std::string name;
	std::string type;
	int id;
	int catchRate;
};