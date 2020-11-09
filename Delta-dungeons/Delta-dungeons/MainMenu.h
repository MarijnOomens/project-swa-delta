#pragma once

#include "Screen.h"
#include <string>
#include <vector>
#include "Button.h"
#include "Color.h"
#include "GraphicsComponent.h"
#include "SceneLoader.h"

class MainMenu : public Screen
{
public:
	std::vector<Button> buttons;

	MainMenu();
	~MainMenu();

	void startGame();
	void openCreditScreen();
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) override;
	void closeScreen() override;

};