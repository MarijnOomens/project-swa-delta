#pragma once

#include <memory>
#include "Screen.h"
#include <vector>
#include <string>
#include "MainMenu.h"
#include "Creditscreen.h"
#include "Helpscreen.h"
#include "GameOverScreen.h"
#include "GameWinScreen.h"
#include "PauseScreen.h"
#include "LoadSaveScreen.h"

class UIManager 
{
public:
	std::map<std::string, std::shared_ptr<Screen>> screens;
	std::map<std::string, std::string> beats;

	void createBaseScreens();
	void playDialogue(std::vector<std::string> param);
	void updateHudHealth(int param);
	void updateHudCollectedCrystals(int param);
	void updateHighScore(int param);
	std::map<std::string, std::string> passTextures();
	std::map<std::string, std::string> passFonts();
	std::map<std::string, std::string> passBeats();
};