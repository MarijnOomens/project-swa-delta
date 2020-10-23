#pragma once
#include <vector>
#include "IEquipment.h"
#include "GameObject.h"
#include "GraphicsComponent.h"
#include <list>

using TextureList = std::vector<std::string>;

class Player : public GameObject {

public:
	Player(int x, int y, TextureList texture, GraphicsComponent* gc);
	~Player();
	void damagePlayer(int damage);
	void updateCaughtPokemon(int id);
	void handleInput(const KeyCodes keyCodes, const KeyboardEvent keyboardEvent) override;
	void addEquipment(std::shared_ptr<IEquipment> equipment);

	static void staticEquipmentCallbackFunction(void* p, const bool runningActivated);
	void equipmentCallbackFunction(const bool runningActivated);

	void callbackFunction() override;
	void connectCallback() override;
	void update() override;


private:
	int health;
	std::list<std::shared_ptr<IEquipment>> equipment;
	int amountCaught;
	std::vector<int> pokemonCaught;
	int baseMovementSpeed;
	GraphicsComponent* m_gc;
	TextureList textureList;

};