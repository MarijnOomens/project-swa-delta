#pragma once

#include "UIManager.h"
#include "EquipmentManager.h"
#include <vector>
#include <string>

class GameManager {
public:
	UIManager* uiManager;
	EquipmentManager* eqManager;

	GameManager();
	~GameManager();

	void RegisterGameObjects();
};