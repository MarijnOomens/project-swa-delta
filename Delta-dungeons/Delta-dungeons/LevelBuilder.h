#pragma once
#include "LevelScene.h"
#include "Vector2D.h"
#include "EquipmentManager.h"
#include "HUDManager.h"
#include "PokemonManager.h"
#include "NPCManager.h"
#include "PlayerManager.h"
#include "EngineFacade.h"
#include "World.h"

typedef void(*cbCamera) (void*, int, int);
typedef void(*cbInteract) (void*, std::shared_ptr<BehaviourObject>, int, int);
typedef void(*cbGameOver) (void*);
typedef void(*cbHUD) (void*, int, int, int);
typedef void(*cbCollision) (void*, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);
typedef void(*cbThrowCollision) (void*, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);

class LevelBuilder
{
public:
	LevelBuilder(const std::string& levelName, std::shared_ptr<EngineFacade> ef);
	~LevelBuilder() {};
	void reset();
	Vector2D setPlayer();
	void setNPCs();
	void setPokemon();
	void setHud();
	void setWorld();
	void setEquipment();
	Scene getResult();

	static void staticCheckCollisionCallbackFunction(void* p, std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w);
	void passCollisionCheck(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w);

	static void staticThrowCollisionCallbackFunction(void* p, std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w);
	void throwCollisionCheck(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w);

	static void staticCameraCallbackFunction(void* p, int x, int y);
	void passPlayerPosition(int x, int y);

	static void staticInteractCallbackFunction(void* p, std::shared_ptr<BehaviourObject> player, int x, int y);
	void interactCallbackFunction(std::shared_ptr<BehaviourObject> player, int x, int y);

	static void staticGameOverbackFunction(void* p);
	void gameOverCallbackFunction();

	static void staticUpdateHUDCallbackFunction(void* p, int health, int berries, int pokeballs);
	void updateHUDCallbackFunction(int health, int berries, int pokeballs);

	static void staticLoadNextLevelCallbackFunction(void* p);
	void loadNextLevelCallbackFunction();

private:
	std::string levelName;
	LevelScene scene;

	PlayerManager playerManager;
	EquipmentManager eqManager;
	NPCManager npcManager;
	PokemonManager pokemonManager;
	HUDManager hudManager;
	std::shared_ptr<World> world;

	std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects;
	std::shared_ptr<EngineFacade> engineFacade;
};
