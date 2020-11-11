#pragma once

#include "Screen.h"
#include <string>
#include <vector>
#include "Button.h"
#include "Color.h"
#include "GraphicsComponent.h"
#include "SceneLoader.h"
#include <sstream>

typedef void(*buttonCb) (const void*);

class MainMenu : public Screen
{
public:
	std::vector<Button> buttons;

	MainMenu();
	~MainMenu() {};

	static void staticOpenGameCallbackFunction(const void* p);
	void openGameCallbackFunction()const;
	static void staticOpenCreditsCallbackFunction(const void* p);
	void openCreditsCallbackFunction()const;
	static void staticOpenHelpCallbackFunction(const void* p);
	void openHelpCallbackFunction()const;
	static void staticExitCallbackFunction(const void* p);
	void exitCallbackFunction()const;

	void handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) override;
};