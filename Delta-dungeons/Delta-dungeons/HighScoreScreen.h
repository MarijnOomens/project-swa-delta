#pragma once
#include "Screen.h"
#include "Button.h"
#include "GameState.h"

class HighScoreScreen : public Screen
{
public:
	HighScoreScreen();
	~HighScoreScreen() {};

	void setParent() override {}
	void start() override;

	static void staticExitCallbackFunction(const void* p);
	void exitCallbackFunction() const;
private:
	std::shared_ptr<TextComponent> beatText;
	std::shared_ptr<TextComponent> highScoreText;
	std::shared_ptr<TextComponent> yourScoreText;
	int score = 0;
};
