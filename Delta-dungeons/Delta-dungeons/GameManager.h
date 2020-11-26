#pragma once

#include "UIManager.h"
#include "EquipmentManager.h"
#include "PlayerManager.h"
#include "EngineFacade.h"
#include "XMLSceneParser.h"
#include "SceneLoader.h"
#include "NPCManager.h"
#include "PokemonManager.h"
#include "Scene.h"
#include "DebugUtilities.h"
#include "SceneModifier.h"
#include "HUDManager.h"

class GameManager {
public:
	GameManager();
	~GameManager() {}

	void registerBehaviourObjects();
	void registerTextures(std::map<std::string, std::string> textures);

	static void staticCheckCollisionCallbackFunction(void* p, std::shared_ptr<ColliderComponent> collider, int x, int y, KeyCodes direction);
	void passCollisionCheck(std::shared_ptr<ColliderComponent> collider, int x, int y, KeyCodes direction);

	static void staticCameraCallbackFunction(void* p, int x, int y);
	void passPlayerPosition(int x, int y);

	void registerFonts(std::map<std::string, std::string> fonts);

	static void staticInteractCallbackFunction(void* p, int x, int y);
	void interactCallbackFunction(int x, int y);

	static void staticUpdateHUDHealthCallbackFunction(void* p, bool hit);
	void updateHUDHealthCallbackFunction(bool hit);
	
	static void staticGameOverbackFunction(void* p);
	void gameOverCallbackFunction();

private:
	std::shared_ptr<EngineFacade> engineFacade;
	std::shared_ptr<Scene> scene;
	UIManager uiManager;
	PlayerManager playerManager;
	EquipmentManager eqManager;
	NPCManager npcManager;
	PokemonManager pokemonManger;
	HUDManager hudManager;
};