#pragma once
#include <string>
#include "InteractiveObject.h"

class Pokemon : InteractiveObject
{

private:
	std::string name;
	std::string type;
	int id;
	int catchRate;

};