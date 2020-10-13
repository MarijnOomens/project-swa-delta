#pragma once
#include "Screen.h"

class PauseScreen: Screen
{

public:
	Screen* helpScreen;
	void saveGame();
	void openHelp();

};