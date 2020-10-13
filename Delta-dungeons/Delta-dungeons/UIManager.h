#pragma once
#include <vector>
#include <string>
#include "Screen.h"

class UIManager {

public:
	std::vector<Screen> screens;
	void playDialogue(std::vector<std::string>);
	void updateHudHealth(int);
	void updateHudCollectedCrystals(int);
	void updateHighScore(int);
};