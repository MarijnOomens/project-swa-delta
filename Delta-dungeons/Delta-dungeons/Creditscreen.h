#pragma once
#include "Screen.h"
#include "Button.h"

class CreditScreen : public Screen {
public:
	CreditScreen();
	~CreditScreen();

	std::vector<Button> buttons;
	void closeScreen() override;
};