#pragma once

#include "Screen.h"
#include <vector>
#include <string>
#include "MainMenu.h"

class UIManager {
public:
	std::map<std::string, std::shared_ptr<Screen>> screens;
	void createBaseScreens();
	void playDialogue(std::vector<std::string>);
	void updateHudHealth(int);
	void updateHudCollectedCrystals(int);
	void updateHighScore(int);
	std::map<std::string, std::string> passTextures();
};