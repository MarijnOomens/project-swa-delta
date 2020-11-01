#pragma once

#include "UIManager.h"
#include "EquipmentManager.h"
#include "PlayerManager.h"
#include "EngineFacade.h"
#include "XMLSceneParser.h"

class GameManager {
public: 
	EngineFacade engineFacade;
	UIManager uiManager;
	PlayerManager playerManager;
	EquipmentManager eqManager;
	Scene scene;
	std::shared_ptr<Player> player;

	GameManager();
	~GameManager();
	void registerBehaviourObjects();
	void registerTextures(std::map<std::string, std::string> textures);

private:
	std::vector<std::shared_ptr<BehaviourObject>> objects; //TODO: split into scenes
};