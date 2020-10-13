#pragma once
#include <vector>
#include "Equipment.h"

class Player {

public:
	void damagePlayer(int damage);
	void updateCaughtPokemon(int id);

private:
	int health;
	std::vector<Equipment> equipment;
	int amountCaught;
	std::vector<int> pokemonCaught;

};