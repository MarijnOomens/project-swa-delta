#pragma once
#include <vector>
#include "IEquipment.h"
#include "GameObject.h"

class Player : public GameObject {

public:
	Player();
	~Player();
	void damagePlayer(int damage);
	void updateCaughtPokemon(int id);
	void handleInput(const KeyCodes keyCodes, const KeyboardEvent keyboardEvent) override;
	void callbackFunction() override;
	void connectCallback() override;
	void addEquipment(IEquipment* equipment);
private:
	int health;
	std::vector<IEquipment> equipment;
	int amountCaught;
	std::vector<int> pokemonCaught;
};