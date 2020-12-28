#pragma once

#include "Screen.h"
#include "TextComponent.h"
#include "SceneLoader.h"
#include "Button.h"
#include "GameState.h"

class LoadSaveScreen : public Screen
{

public:
	LoadSaveScreen();

	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void setParent() override {}

	static void staticLoadCallbackFunction(const void* p);
	void loadCallbackFunction() const;
	static void staticBackCallbackFunction(const void* p);
	void backCallbackFunction() const;
	static void staticNewCallbackFunction(const void* p);
	void newCallbackFunction() const;
};