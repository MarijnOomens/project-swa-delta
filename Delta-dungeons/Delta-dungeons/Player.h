#pragma once
#include <vector>
#include "IEquipment.h"
#include "GameObject.h"
#include "GraphicsComponent.h"
#include <list>

class Player : public GameObject {

public:
	Player();
	Player(std::string texture, std::shared_ptr<GraphicsComponent> gc);
	~Player();

	void handleInput(const KeyCodes keyCodes, const KeyboardEvent keyboardEvent) override;
	void addEquipment(std::shared_ptr<IEquipment> equipment);
	static void staticEquipmentCallbackFunction(void* p, const bool runningActivated);
	void equipmentCallbackFunction(const bool runningActivated);

	void damagePlayer(int damage);
	void updateCaughtPokemon(int pokemonId);
	void callbackFunction() override;
	void connectCallback() override;
	void update() override;

private:
	int health;
	int amountCaught;
	int baseMovementSpeed;
	std::vector<int> pokemonCaught;
	std::vector<std::shared_ptr<IEquipment>> equipment;
	std::shared_ptr<GraphicsComponent> m_gc;
};