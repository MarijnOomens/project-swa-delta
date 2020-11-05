#pragma once

#include "Screen.h"
#include "TextComponent.h"

class HelpScreen : public Screen
{

public:
	HelpScreen();
	~HelpScreen();

	void closeScreen() override;

};