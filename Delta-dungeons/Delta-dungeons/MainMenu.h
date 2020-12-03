#pragma once

#include "Screen.h"
#include <string>
#include <vector>
#include "Button.h"
#include "Color.h"
#include "GraphicsComponent.h"
#include "Advertisement.h"
#include "SceneLoader.h"
#include <sstream>
#include "AudioUtilities.h"

class MainMenu : public Screen
{
public:
	MainMenu();

	void start() override;
	void setParent() override;

	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;

	static void staticOpenGameCallbackFunction(const void* p);
	void openGameCallbackFunction()const;
	static void staticOpenCreditsCallbackFunction(const void* p);
	void openCreditsCallbackFunction()const;
	static void staticOpenHelpCallbackFunction(const void* p);
	void openHelpCallbackFunction()const;
	static void staticExitCallbackFunction(const void* p);
	void exitCallbackFunction()const;

private:
	std::vector<Button> buttons;
};