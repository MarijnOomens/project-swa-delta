#pragma once

#include "IEquipment.h"
#include "Boomerang.h"
#include "InteractiveObject.h"
#include "GraphicsComponent.h"
#include "CollidingComponent.h"
#include "RunningShoes.h"
#include "DebugUtilities.h"
#include "StopStrategy.h"

typedef void(*cbInteract) (void*, int, int);
typedef void(*cbCamera) (void*, int, int);
typedef void(*cbGameOver) (void*);
typedef void(*cbHUD) (void*, bool);
typedef void(*cbCollision) (void*, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);
typedef void(*cbNextLevel) (void*);

class Player : public InteractiveObject, public std::enable_shared_from_this<BehaviourObject>
{
public:
	std::map<std::string, std::string> textures;
	std::string texture;

	cbCamera func;
	cbInteract interactFunc;
	cbGameOver gameOverFunc;
	cbHUD hudFunc;
	cbCollision collisionFunc;
	cbNextLevel nextLevelFunc;
	KeyCodes currentDirection;
	void* pointer;

	Player(int spawnX, int spawnY, cbCollision collisionCB, cbNextLevel nextLevelcb, cbCamera f, cbInteract interactCB, cbGameOver gameOverFunc, cbHUD hudCB, void* p);

	void handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void interact() override;
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned) override;
	void handleKeyPressed(const KeyCodes& keyCodes);
	void handleKeyReleased(const KeyCodes& keyCodes);

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void addEquipment(std::unique_ptr<IEquipment> equipment);
	void damagePlayer(int damage);
	void updateCaughtPokemon(int pokemonId);
	std::vector<std::string> getItems();
	std::shared_ptr<CollidingComponent> getCollider();

	static void staticBoomerangCallbackFunction(void* p, const bool boomerangActivated);
	void boomerangCallbackFunction(const bool boomerangActivated);

	static void staticRunningShoesCallbackFunction(void* p, const bool runningActivated);
	void runningShoesCallbackFunction(const bool runningActivated);

	void update() override;
	void handleInteraction();
	void registerHit();
private:
	const int animationSpeed = 130;
	int health;
	int amountCaught;
	int baseMovementSpeed;
	int x, y;
	int count;
	bool isWalking = true;
	bool boomerangActivated = false;
	bool cheatCollision = false;
	bool hasMoved = false;
	std::vector<int> pokemonCaught;
	std::vector<std::unique_ptr<IEquipment>> equipment;
	std::shared_ptr<StopStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
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