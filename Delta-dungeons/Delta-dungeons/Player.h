#pragma once

#include "IEquipment.h"
#include "GameObject.h"
#include "GraphicsComponent.h"
typedef void(*cbCamera) (void*,int,int);
typedef void(*cbTile) (void*, int, int);


class Player : public GameObject {
public:
	std::map<std::string, std::string> textures;
	std::string texture;
	cbCamera func;
	cbTile tileFunc;
	void* pointer;
	bool tileCollision;
	Player();
	Player(const cbCamera f, const cbTile cbTile, void* p);
	~Player();

	void handleInput(const KeyCodes keyCodes, const KeyboardEvent keyboardEvent, Vector2D mousePos) override;
	void handleKeyPressed(const KeyCodes keyCodes);
	void handleKeyReleased(const KeyCodes keyCodes);

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();


	void addEquipment(std::shared_ptr<IEquipment> equipment);
	static void staticEquipmentCallbackFunction(void* p, const bool runningActivated);
	void equipmentCallbackFunction(const bool runningActivated);

	static void staticTileCallbackFunction(void* p);

	void damagePlayer(int damage);
	void updateCaughtPokemon(int pokemonId);
	void update() override;
	void setToTrue();
private:
	int health;
	int amountCaught;
	int baseMovementSpeed;
	int x, y;
	int predictedX; //cant initialise to 0 here, because it will still give random value
	int	predictedY;
	int count;
	bool runActivated;
	bool cheatCollision = false;
	std::vector<int> pokemonCaught;
	std::vector<std::shared_ptr<IEquipment>> equipment;
	std::shared_ptr<GraphicsComponent> m_gc;
	AnimCategory animCategory;
};