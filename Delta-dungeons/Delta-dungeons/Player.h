#pragma once

#include "IEquipment.h"
#include "Boomerang.h"
#include "GameObject.h"
#include "GraphicsComponent.h"
#include "ColliderComponent.h"
typedef void(*cbInteract) (void*, int, int);
typedef void(*cbCamera) (void*, int, int);

class Player : public GameObject
{
public:
	std::map<std::string, std::string> textures;
	std::string texture;
	cbCamera func;
	cbInteract npcManagerFunc;
	KeyCodes currentDirection;
	Vector2D temporaryColliderPosition;
	void* pointer;
	bool tileCollision;

	int rightX;
	int leftX;
	int upY;
	int downY;
	//std::string colliderTag;

	Player(cbCamera f, cbInteract npcMF, void* p);
	~Player() {}

	void handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void interact() override;
	void handleKeyPressed(const KeyCodes& keyCodes);
	void handleKeyReleased(const KeyCodes& keyCodes);

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void addEquipment(std::unique_ptr<IEquipment> equipment);
	void damagePlayer(int damage);
	void updateCaughtPokemon(int pokemonId);
	
	static void staticCollisionCallbackFunction(void* p, int right, int left, int up, int down);
	void collisionCallbackFunction(int right, int left, int up, int down);

	static void staticEquipmentCallbackFunction(void* p, const bool runningActivated);
	void equipmentCallbackFunction(const bool runningActivated);

	void update() override;
	void handleInteraction();
private:
	const int animationSpeed = 120;
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
	std::shared_ptr<ColliderComponent> cc;
	AnimCategory animCategory;
};