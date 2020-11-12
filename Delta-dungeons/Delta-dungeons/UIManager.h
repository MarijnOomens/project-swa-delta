#pragma once

#include <memory>
#include "Screen.h"
#include <vector>
#include <string>
#include "MainMenu.h"
#include "Creditscreen.h"
#include "Helpscreen.h"
#include "GameOverScreen.h"
#include "PauseScreen.h"

class UIManager 
{
public:
	std::map<std::string, std::shared_ptr<Screen>> screens;

	void createBaseScreens();
	void playDialogue(std::vector<std::string> param);
	void updateHudHealth(int param);
	void updateHudCollectedCrystals(int param);
	void updateHighScore(int param);
	std::map<std::string, std::string> passTextures();
	std::map<std::string, std::string> passFonts();

};