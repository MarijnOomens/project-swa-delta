#pragma once

#include "Screen.h"
#include "TextComponent.h"
#include "Button.h"
#include "SceneLoader.h"

class GameWinScreen : public Screen
{
public:
	GameWinScreen();
	~GameWinScreen() {}
	void setParent() override;

	static void staticExitCallbackFunction(const void* p);
	void exitCallbackFunction() const;
};

