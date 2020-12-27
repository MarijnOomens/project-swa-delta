#pragma once

#include "IEquipment.h"
#include "Boomerang.h"
#include "IInteractiveObject.h"
#include "GraphicsComponent.h"
#include "CollidingComponent.h"
#include "RunningShoes.h"
#include "DebugUtilities.h"
#include "StopStrategy.h"
#include "ThrowPokeball.h"
#include "SceneLoader.h"
#include "AudioUtilities.h"

typedef void(*cbInteract) (void*, std::shared_ptr<BehaviourObject>, int, int, int, int);
typedef void(*cbCamera) (void*, int, int);
typedef void(*cbGameOver) (void*);
typedef void(*cbCollision) (void*, std::shared_ptr<CollidingComponent>, std::shared_ptr<BehaviourObject> behaviourObject, int, int, KeyCodes, int);
typedef void(*cbThrowCollision) (void*, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);
typedef void(*cbNextLevel) (void*);

class Player : public IInteractiveObject
{
public:
	std::map<std::string, std::string> textures;
	std::string texture;

	std::shared_ptr<ThrowPokeball> pokeball;

	cbCamera func;
	cbInteract interactFunc;
	cbGameOver gameOverFunc;
	cbCollision collisionFunc;
	cbNextLevel nextLevelFunc;
	KeyCodes currentDirection;
	void* pointer;
	void* gmPointer;

	Player(int spawnX, int spawnY, cbCollision collisionCB, cbThrowCollision throwCB, cbNextLevel nextLevelcb, cbCamera f, cbInteract interactCB, cbGameOver gameOverFunc, void* p, void* gm);

	void handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) override;
	void handleKeyPressed(const KeyCodes& keyCodes);
	void handleKeyReleased(const KeyCodes& keyCodes);

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void addEquipment(std::unique_ptr<IEquipment> equipment);
	void updateCaughtPokemon(int pokemonId) {}
	std::vector<std::string> getItems();
	std::shared_ptr<CollidingComponent> getCollider();

	static void staticBoomerangCallbackFunction(void* p, const bool boomerangActivated);
	void boomerangCallbackFunction(const bool boomerangActivated);

	static void staticRunningShoesCallbackFunction(void* p, const bool runningActivated);
	void runningShoesCallbackFunction(const bool runningActivated);

	static void staticPokeballCallbackFunction(void* p);
	void pokeballCallbackFunction();

	void update() override {}
	void setParent() override;
	void start() override;
	void handleInteraction();
	void registerHit();
	void eatBerry();
	void addBerry();
	void usePokeball();
	void addPokeball();
	void getIdleAnimation();

	int health = 0;
	int maxHealth = 5;
	int amountOfBerries = 0;
	int amountOfPokeballs = 0;
	int amountOfPokemons = 0;
private:
	const int animationSpeed = 180;
	int amountCaught = 0;
	int baseMovementSpeed;
	int x, y;
	int count;
	bool isWalking = true;
	bool boomerangActivated = false;
	bool hasMoved = false;
	bool noCollisionCheat = false;
	bool noDamageCheat = false;
	bool infinteBerries = false;
	bool infinitePokeballs = false;
	bool isNewLevel = false;
	std::vector<int> pokemonCaught;
	std::vector<std::unique_ptr<IEquipment>> equipment;
	std::shared_ptr<StopStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	AnimCategory animCategory;
	bool tileCollision;
};