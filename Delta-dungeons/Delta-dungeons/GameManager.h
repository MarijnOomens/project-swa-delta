#pragma once
#include <vector>
#include <string>
#include "UIManager.h"

class GameManager {

public: 

	UIManager* uiManager;
	std::vector<GameObject>  gameObjects;

	GameManager();
	void RegisterGameObjects();
};