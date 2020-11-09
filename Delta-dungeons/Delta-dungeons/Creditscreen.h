#pragma once
#include "Screen.h"
#include "Button.h"
#include "TextComponent.h"
#include "SceneLoader.h"

class CreditScreen : public Screen {
public:
	CreditScreen();
	~CreditScreen();

	std::vector<Button> buttons;
	void closeScreen() override;
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos) override;

};