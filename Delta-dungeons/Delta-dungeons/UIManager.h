#pragma once

#include "Screen.h"
#include <vector>
#include <string>

class UIManager {
public:
	std::vector<Screen> screens;

	void playDialogue(std::vector<std::string>);
	void updateHudHealth(int);
	void updateHudCollectedCrystals(int);
	void updateHighScore(int);
};