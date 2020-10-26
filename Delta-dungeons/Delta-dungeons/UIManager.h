#pragma once
#include <vector>
#include <string>
#include "Screen.h"
#include "MainMenu.h"

class UIManager {

public:
	std::map<std::string, std::unique_ptr<Screen>> screens;
	void createBaseScreens();
	void playDialogue(std::vector<std::string>);
	void updateHudHealth(int);
	void updateHudCollectedCrystals(int);
	void updateHighScore(int);
};