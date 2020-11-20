#pragma once

#include "Screen.h"
#include "Button.h"
#include "TextComponent.h"
#include "SceneLoader.h"

class CreditScreen : public Screen 
{
public:
	CreditScreen();

	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;

	static void staticBackCallbackFunction(const void* p);
	void backCallbackFunction() const;

private:
	std::vector<Button> buttons;
};