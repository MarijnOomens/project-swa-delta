#pragma once
#include "Screen.h"
#include "Button.h"
#include "TextComponent.h"

class PauseScreen : public Screen
{
public:
	PauseScreen();
	~PauseScreen();

	//Screen* helpScreen;
	std::vector<Button> buttons;

	void saveGame();
	void openHelp(); 
	void closeScreen() override;
};