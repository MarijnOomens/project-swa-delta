#pragma once
#include "Screen.h"
#include <string>
#include <vector>
#include "Button.h"

class MainMenu : Screen
{
public:
	MainMenu(); //yes or no
	MainMenu(std::string txt, Vector2D textLoc, std::vector<Button> bttns);
	~MainMenu();

	Screen* creditScreen;
	void startGame();
	void openCreditScreen();
	std::vector<Button> buttons;
	Vector2D textLocation; //Maybe?
};