#pragma once

#include "Screen.h"
#include "TextComponent.h"
#include "SceneLoader.h"
#include "Button.h"

class HelpScreen : public Screen
{

public:
	HelpScreen();
	~HelpScreen();

	static void staticBackCallbackFunction(void* p);

	void backCallbackFunction();

	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos) override;
};