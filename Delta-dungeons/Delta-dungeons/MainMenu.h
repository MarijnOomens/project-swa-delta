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
	std::vector<Button> buttons;

	MainMenu();
	~MainMenu();

	void startGame();
	void openCreditScreen();
	void openHelpScreen();
	void closeScreen() override;
};