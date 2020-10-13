#pragma once
#include <vector>
#include <string>
#include "UIManager.h"
#include "EquipmentManager.h"

class GameManager {

public: 

	UIManager* uiManager;
	EquipmentManager* eqManager;

	GameManager();
	void RegisterGameObjects();
};