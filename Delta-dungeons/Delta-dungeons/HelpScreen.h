#pragma once

#include "Screen.h"
#include "TextComponent.h"
#include "SceneLoader.h"
#include "Button.h"

class HelpScreen : public Screen
{

public:
	HelpScreen();

	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void setParent() override;

	static void staticBackCallbackFunction(const void* p);
	void backCallbackFunction() const;
};