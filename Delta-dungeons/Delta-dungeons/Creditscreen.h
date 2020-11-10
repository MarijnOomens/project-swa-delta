#pragma once
#include "Screen.h"
#include "Button.h"
#include "TextComponent.h"
#include "SceneLoader.h"

class CreditScreen : public Screen {
public:
	CreditScreen();
	~CreditScreen();

	static void staticBackCallbackFunction(void* p);
	void backCallbackFunction();

	std::vector<Button> buttons;
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos) override;

};