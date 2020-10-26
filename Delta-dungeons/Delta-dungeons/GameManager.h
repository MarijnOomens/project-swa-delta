#pragma once
#include <vector>
#include <string>
#include "UIManager.h"
#include "EquipmentManager.h"
#include "EngineFacade.h"

class GameManager {
private:
	std::vector<std::unique_ptr<BehaviourObject>> objects; //TODO: split into scenes

public: 
	EngineFacade engineFacade;
	UIManager uiManager;
	EquipmentManager* eqManager;

	GameManager();
	void RegisterGameObjects();
};