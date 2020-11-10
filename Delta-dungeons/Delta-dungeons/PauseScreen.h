#pragma once
#include "Screen.h"
#include "Button.h"
#include "TextComponent.h"
#include "SceneLoader.h"

class PauseScreen : public Screen
{
public:
	PauseScreen();
	~PauseScreen();

	static void staticOpenHelpCallbackFunction(void* p);
	void openHelpCallbackFunction();
	static void staticSaveCallbackFunction(void* p);
	void saveCallbackFunction();
	static void staticExitCallbackFunction(void* p);
	void exitCallbackFunction();

	//Screen* helpScreen;
	std::vector<Button> buttons;

	void saveGame();
	void openHelp(); 
};