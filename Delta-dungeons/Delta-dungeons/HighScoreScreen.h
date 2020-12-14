#pragma once
#include "Screen.h"
#include "Button.h"

class HighScoreScreen : public Screen
{
public:
	HighScoreScreen();
	~HighScoreScreen() {};

	void setParent() override;

	static void staticExitCallbackFunction(const void* p);
	void exitCallbackFunction() const;
};
