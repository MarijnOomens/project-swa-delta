#pragma once

#include "UIManager.h"
#include "EquipmentManager.h"
#include "PlayerManager.h"
#include "EngineFacade.h"

class GameManager {
public: 
	EngineFacade engineFacade;
	UIManager uiManager;
	PlayerManager playerManager;
	EquipmentManager eqManager;

	GameManager();
	~GameManager();
	void registerBehaviourObjects();
	void registerTextures(std::map<std::string, std::string> textures);
	void registerFonts(std::map<std::string, std::string> fonts);

private:
	std::vector<std::shared_ptr<BehaviourObject>> objects; //TODO: split into scenes
};