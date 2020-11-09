#pragma once

#include "Screen.h"
#include <string>
#include <vector>
#include "Button.h"
#include "Color.h"
#include "GraphicsComponent.h"
#include "SceneLoader.h"

typedef void(*buttonCb) (void*);

class MainMenu : public Screen
{
public:
	std::vector<Button> buttons;

	static void staticOpenGameCallbackFunction(void* p);
	void openGameCallbackFunction();

	MainMenu();
	~MainMenu();

	void startGame();
	void openCreditScreen();
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos) override;
	void closeScreen() override;

};