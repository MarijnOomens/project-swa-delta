#pragma once
#include "Screen.h"

class MainMenu: Screen
{

public:
	Screen* creditScreen;
	void startGame();
	void openCreditScreen();

};