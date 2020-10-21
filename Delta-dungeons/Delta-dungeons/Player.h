#pragma once
#include <vector>
#include "IEquipment.h"
#include "GameObject.h"
#include <list>
class Player : public GameObject {

public:
	Player();
	~Player();
	void damagePlayer(int damage);
	void updateCaughtPokemon(int id);
	void handleInput(const KeyCodes keyCodes, const KeyboardEvent keyboardEvent) override;
	void callbackFunction() override;
	void connectCallback() override;
	void addEquipment(std::shared_ptr<IEquipment> equipment);
private:
	int health;
	std::list<std::shared_ptr<IEquipment>> equipment;
	int amountCaught;
	std::vector<int> pokemonCaught;
};