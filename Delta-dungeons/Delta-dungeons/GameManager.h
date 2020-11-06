#pragma once

#include "UIManager.h"
#include "EquipmentManager.h"
#include "PlayerManager.h"
#include "EngineFacade.h"
#include "XMLSceneParser.h"
#include "NPCManager.h"

class GameManager {
public: 
	EngineFacade engineFacade;
	UIManager uiManager;
	std::shared_ptr<PlayerManager> playerManager;
	EquipmentManager eqManager;
	Scene scene;
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
	std::vector<std::shared_ptr<BehaviourObject>> objects; //TODO: split into scenes
};