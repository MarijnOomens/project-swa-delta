#pragma once

#include "IEquipment.h"
#include "Boomerang.h"
#include "GameObject.h"
#include "GraphicsComponent.h"

typedef void(*cbCamera) (const void*, int, int);

class Player : public GameObject 
{
public:
	std::map<std::string, std::string> textures;

	Player(cbCamera f, const void* p);
	~Player() {};

	void handleInput(const KeyCodes &keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void handleKeyPressed(const KeyCodes& keyCodes);
	void handleKeyReleased(const KeyCodes& keyCodes);

	void update() override;

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void addEquipment(std::unique_ptr<IEquipment> equipment);
	void damagePlayer(int damage);
	void updateCaughtPokemon(int pokemonId);
	std::vector<std::string> getItems();

	static void staticEquipmentCallbackFunction(void* p, const bool runningActivated);
	void equipmentCallbackFunction(const bool runningActivated);

private:
	int health;
	int amountCaught;
	int baseMovementSpeed;

	std::string texture;
	cbCamera func;
	const void* pointer;

	bool runActivated;
	const int animationSpeed = 120;

	std::vector<int> pokemonCaught;
	std::vector<std::unique_ptr<IEquipment>> equipment;
	std::shared_ptr<GraphicsComponent> gc;
	AnimCategory animCategory;
};