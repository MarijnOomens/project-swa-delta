#pragma once

//#include "UIManager.h"
#include "MainMenuScene.h"
#include "EquipmentManager.h"
#include "PlayerManager.h"
#include "EngineFacade.h"
#include "XMLSceneParser.h"
#include "SceneLoader.h"
#include "NPCManager.h"
#include "PokemonManager.h"
#include "World.h"
#include "DebugUtilities.h"
#include "SceneModifier.h"
#include "HUDManager.h"
#include "AudioUtilities.h"

class GameManager {
public:
	GameManager();
	~GameManager() {}

	void registerBehaviourObjects();
	void registerTextures(std::map<std::string, std::string> textures);
	void registerFonts(std::map<std::string, std::string> fonts);
	void registerAudio(std::map<std::string, std::string> beats);

	void createLevel(std::string levelName);

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
	std::shared_ptr<EngineFacade> engineFacade;
	std::shared_ptr<World> world;
	//UIManager uiManager;
	MainMenuScene mainMenuScene;
	PlayerManager playerManager;
	EquipmentManager eqManager;
	NPCManager npcManager;
	PokemonManager pokemonManager;
	HUDManager hudManager;
	std::vector<std::string> levels{ "Level1", "Dungeon1","Level2", "Dungeon2","Level3", "Dungeon3", "Level4" };
	int currentlevel = 0;
};