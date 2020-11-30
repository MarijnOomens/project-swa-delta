#pragma once

#include "Screen.h"
#include "TextComponent.h"
#include "Button.h"
#include "SceneLoader.h"

class GameOverScreen : public Screen
{
public:
	GameOverScreen();
	~GameOverScreen() {}

	void restartGame();
	void setParent() override;

	static void staticExitCallbackFunction(const void* p);
	void exitCallbackFunction() const;
};