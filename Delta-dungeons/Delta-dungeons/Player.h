#pragma once
#include <vector>
#include "Equipment.h"

class Player {

public:
	void DamagePlayer(int damage);

private:
	int health;
	std::vector<Equipment> equipment;

};