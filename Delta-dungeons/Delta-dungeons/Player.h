#pragma once

#include "IEquipment.h"
#include "GameObject.h"
#include "GraphicsComponent.h"
typedef void(*cbCamera) (void*,int,int);

class Player : public GameObject {
public:
	std::map<std::string, std::string> textures;
	std::string texture;
	cbCamera func;
	void* pointer;

	Player(const cbCamera f, void* p);
	~Player();

	void handleInput(const KeyCodes keyCodes, const KeyboardEvent keyboardEvent) override;
	void handleKeyPressed(const KeyCodes keyCodes);
	void handleKeyReleased(const KeyCodes keyCodes);

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();


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
	int x, y;

	bool runActivated;
	std::vector<int> pokemonCaught;
	std::vector<std::shared_ptr<IEquipment>> equipment;
	std::shared_ptr<GraphicsComponent> m_gc;
	AnimCategory animCategory;
};