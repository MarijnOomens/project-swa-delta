#pragma once

#include "Screen.h"
#include "TextComponent.h"
#include "Button.h"

class GameWinScreen : public Screen
{
public:
	GameWinScreen();
	~GameWinScreen();

	void closeScreen() override;
};

