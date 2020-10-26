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
	MainMenu(); //yes or no
	~MainMenu();

	Screen* creditScreen;
	void startGame();
	void openCreditScreen();

	void closeScreen() override;
};