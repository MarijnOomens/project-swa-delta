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

class GameManager {
public: 
	std::shared_ptr<EngineFacade> engineFacade;
	UIManager uiManager;
	PlayerManager playerManager;
	EquipmentManager eqManager;
	std::shared_ptr<Scene> scene;
	NPCManager npcManager;

	GameManager();
	~GameManager();
	void registerBehaviourObjects();
	void registerTextures(std::map<std::string, std::string> textures);
	static void staticCameraCallbackFunction(void* p,int x, int y);

	static void staticPlayerToTileCallbackFunction(void* p, int x, int y);
	static void staticTileToPlayerCallbackFunction(void* p);
	void playerToTileCallbackFunction(int x, int y);

	void tileToPlayerCallbackFunction();

	void passPlayerPosition(int x, int y);
	void registerFonts(std::map<std::string, std::string> fonts);

private:

};