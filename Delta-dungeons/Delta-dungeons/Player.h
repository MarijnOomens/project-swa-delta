#pragma once
#include <vector>
#include "Equipment.h"
#include "GameObject.h"

class Player : public GameObject {

public:
	void damagePlayer(int damage);
	void updateCaughtPokemon(int id);
	void handleInput(const KeyCodes keyCodes, const KeyboardEvent keyboardEvent) override;
	void callbackFunction() override;
	void connectCallback() override;
private:
	int health;
	std::vector<Equipment> equipment;
	int amountCaught;
	std::vector<int> pokemonCaught;
};