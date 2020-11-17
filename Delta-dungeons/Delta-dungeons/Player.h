#pragma once

#include "IEquipment.h"
#include "Boomerang.h"
#include "GameObject.h"
#include "GraphicsComponent.h"
#include "ColliderComponent.h"
#include "RunningShoes.h"
#include "DebugUtilities.h"

typedef void(*cbInteract) (void*, int, int);
typedef void(*cbCamera) (void*, int, int);

class Player : public GameObject
{
public:
	std::map<std::string, std::string> textures;
	std::string texture;

	cbCamera func;
	cbInteract interactFunc;

	KeyCodes currentDirection;
	void* pointer;

	Player(cbCamera f, cbInteract interactCB, void* p);
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

	static void staticCollisionCallbackFunction(void* p, int right, int left, int up, int down, std::string rightTag, std::string leftTag, std::string upTag, std::string downTag);
	void collisionCallbackFunction(int right, int left, int up, int down, std::string rightTag, std::string leftTag, std::string upTag, std::string downTag);

	static void staticBoomerangCallbackFunction(void* p, const bool boomerangActivated);
	void boomerangCallbackFunction(const bool boomerangActivated);

	static void staticRunningShoesCallbackFunction(void* p, const bool runningActivated);
	void runningShoesCallbackFunction(const bool runningActivated);

	void update() override;
	void handleInteraction();
private:
	const int animationSpeed = 120;
	int health;
	int amountCaught;
	int baseMovementSpeed;
	int x, y;
	int count;
	bool runActivated = false;
	bool boomerangActivated = false;
	bool cheatCollision = false;
	std::vector<int> pokemonCaught;
	std::vector<std::unique_ptr<IEquipment>> equipment;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<ColliderComponent> cc;
	AnimCategory animCategory;
	int rightX;
	int leftX;
	int upY;
	int downY;
	std::string rightTag;
	std::string leftTag;
	std::string upTag;
	std::string downTag;
	bool tileCollision;
};