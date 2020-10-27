#pragma once

#include "UIManager.h"
#include "EquipmentManager.h"
#include "EngineFacade.h"

class GameManager {
private:
	std::vector<std::shared_ptr<BehaviourObject>> objects; //TODO: split into scenes

public: 
	EngineFacade engineFacade;
	UIManager uiManager;
	EquipmentManager* eqManager;

	GameManager();
	~GameManager();
	void registerBehaviourObjects();
	void registerTextures(std::map<std::string, std::string> textures);
};