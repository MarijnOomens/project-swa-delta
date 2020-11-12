#pragma once

#include "Screen.h"
#include "Button.h"
#include "TextComponent.h"
#include "SceneLoader.h"

class PauseScreen : public Screen
{
public:
	PauseScreen();
	~PauseScreen() {}

	static void staticOpenHelpCallbackFunction(const void* p);
	void openHelpCallbackFunction() const;
	static void staticSaveCallbackFunction(const void* p);
	void saveCallbackFunction() const;
	static void staticExitCallbackFunction(const void* p);
	void exitCallbackFunction() const;

private:
	std::vector<Button> buttons;
};