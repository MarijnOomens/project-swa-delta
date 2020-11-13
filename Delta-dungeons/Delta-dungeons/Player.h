#pragma once

#include "IEquipment.h"
#include "Boomerang.h"
#include "GameObject.h"
#include "GraphicsComponent.h"
typedef void(*cbCamera) (void*,int,int);
typedef void(*cbTile) (void*, int, int);
typedef void(*cbInteractWithEquipmentManager) (void*, int, int);
typedef void(*cbInteractWithNPCManager) (void*, int, int);


typedef void(*cbCamera) (const void*, int, int);

class Player : public GameObject 
{
public:
	std::map<std::string, std::string> textures;
	std::string texture;
	cbCamera func;
	cbTile tileFunc;
	cbInteractWithEquipmentManager eqManagerFunc;
	cbInteractWithNPCManager npcManagerFunc;
	KeyCodes currentDirection;
	void* pointer;
	bool tileCollision;
	Player();
	Player(const cbCamera f, const cbTile cbTile, const cbInteractWithEquipmentManager eqMF, void* p);
	~Player() {}

	void handleInput(const KeyCodes &keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void handleKeyPressed(const KeyCodes& keyCodes);
	void handleKeyReleased(const KeyCodes& keyCodes);

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void addEquipment(std::unique_ptr<IEquipment> equipment);
	void damagePlayer(int damage);
	void updateCaughtPokemon(int pokemonId);

	static void staticEquipmentCallbackFunction(void* p, const bool runningActivated);
	void equipmentCallbackFunction(const bool runningActivated);
	static void staticTileCallbackFunction(void* p);

	void update() override;
	void setToTrue();
	void handleInteraction();
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
	std::vector<std::unique_ptr<IEquipment>> equipment;
	std::shared_ptr<GraphicsComponent> gc;
	AnimCategory animCategory;
};