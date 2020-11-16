#pragma once

#include "UIManager.h"
#include "EquipmentManager.h"
#include "PlayerManager.h"
#include "EngineFacade.h"
#include "XMLSceneParser.h"
#include "SceneLoader.h"
#include "NPCManager.h"
#include "Scene.h"
#include "DebugUtilities.h"
#include "SceneModifier.h"

class GameManager {
public:
	GameManager();
	~GameManager() {}

	void registerBehaviourObjects();
	void registerTextures(std::map<std::string, std::string> textures);

	static void staticPlayerToTileCallbackFunction(void* p, int x, int y);
	static void staticCameraCallbackFunction(void* p, int x, int y);
	static void staticInteractCallbackFunction(void* p, int x, int y);
	static void staticCollisionCallbackFunction(void* p, int x, int y, std::string tag);

	void playerToTileCallbackFunction(int x, int y);
	void npcManagerCallbackFunction(int x, int y);
	void collisionCallbackFunction(int x, int y, std::string tag);

	void passPlayerPosition(int x, int y);
	void registerFonts(std::map<std::string, std::string> fonts);

private:
	std::shared_ptr<EngineFacade> engineFacade;
	std::shared_ptr<Scene> scene;
	UIManager uiManager;
	PlayerManager playerManager;
	EquipmentManager eqManager;
	NPCManager npcManager;
};