#pragma once
#include "IEquipment.h"
#include "Boomerang.h"
#include "GameObject.h"
#include "GraphicsComponent.h"
typedef void(*cbCamera) (const void*,int,int);

class Player : public GameObject {
public:
	std::map<std::string, std::string> textures;
	std::string texture;
	cbCamera func;
	const void* pointer;

	Player(cbCamera f, const void* p);
	~Player() {};

	void handleInput(const KeyCodes &keyCodes, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) override;
	void handleKeyPressed(const KeyCodes keyCodes);
	void handleKeyReleased(const KeyCodes keyCodes);

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();


	void addEquipment(std::unique_ptr<IEquipment> equipment);
	static void staticEquipmentCallbackFunction(void* p, const bool runningActivated);
	void equipmentCallbackFunction(const bool runningActivated);

	void damagePlayer(int damage);
	void updateCaughtPokemon(int pokemonId);
	void update() override;

private:
	int health;
	int amountCaught;
	int baseMovementSpeed;

	bool runActivated;
	std::vector<int> pokemonCaught;
	std::vector<std::unique_ptr<IEquipment>> equipment;
	std::shared_ptr<GraphicsComponent> gc;
	AnimCategory animCategory;
};