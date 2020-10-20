#pragma once
#include "Screen.h"
#include <vector>
#include "Button.h"

class MainMenu : Screen
{

public:
	Screen* creditScreen;
	void startGame();
	void openCreditScreen();
	std::vector<Button> buttons;
};