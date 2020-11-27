#pragma once

#include "Screen.h"
#include "TextComponent.h"
#include "SceneLoader.h"
#include "Button.h"

class LoadSaveScreen : public Screen
{

public:
	LoadSaveScreen();

	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;

	static void staticLoad1CallbackFunction(const void* p);
	void load1CallbackFunction() const;
	static void staticBackCallbackFunction(const void* p);
	void backCallbackFunction() const;
};