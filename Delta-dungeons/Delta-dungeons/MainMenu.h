#pragma once

#include "Screen.h"
#include <string>
#include <vector>
#include "Button.h"
#include "Color.h"
#include "GraphicsComponent.h"

class MainMenu : public Screen
{
public:
	Screen* creditScreen;
	Vector2D textLocation; //Maybe?
	std::vector<Button> buttons;

	MainMenu(); //yes or no
	~MainMenu();

	void startGame();
	void openCreditScreen();
	void closeScreen() override;
};