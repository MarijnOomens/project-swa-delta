#pragma once

#include "Screen.h"
#include "Button.h"
#include <string>
#include <vector>

class MainMenu : Screen
{
public:
	Screen* creditScreen;
	Vector2D textLocation; //Maybe?
	std::vector<Button> buttons;

	MainMenu(); //yes or no
	MainMenu(std::string txt, Vector2D textLoc, std::vector<Button> bttns);
	~MainMenu();

	void startGame();
	void openCreditScreen();
};