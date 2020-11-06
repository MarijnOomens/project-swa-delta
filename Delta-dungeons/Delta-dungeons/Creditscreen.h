#pragma once
#include "Screen.h"
#include "Button.h"
#include "TextComponent.h"

class CreditScreen : public Screen {
public:
	CreditScreen();
	~CreditScreen();

	std::vector<Button> buttons;
	void closeScreen() override;
};