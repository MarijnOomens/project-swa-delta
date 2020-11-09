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
	Vector2D textLocation; //Maybe?
	std::vector<Button> buttons;

	MainMenu(); //yes or no
	~MainMenu();

	void startGame();
	void openCreditScreen();
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) override;
	void closeScreen() override;

};