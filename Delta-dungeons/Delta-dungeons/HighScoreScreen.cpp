#include "HighScoreScreen.h"

HighScoreScreen::HighScoreScreen()
{
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("high_score");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	// Main menu button
	std::vector<std::string> possibleButtonTexMainMenu = { "button_exit" };
	std::shared_ptr<Button> mainMenuButton = std::make_shared<Button>(512, 750, possibleButtonTexMainMenu, staticExitCallbackFunction, this);
	this->components.emplace_back(mainMenuButton);

	std::string score = "67";

	Colour color = { 255, 255, 255, 255 };
	std::shared_ptr<TextComponent> highScoreText = std::make_shared<TextComponent>("HIGH SCORE: " + score, "joystix", color, 64);
	highScoreText->transform.position = { 275, 450 };
	this->components.emplace_back(highScoreText);
}

void HighScoreScreen::staticExitCallbackFunction(const void* p)
{
	((HighScoreScreen*)p)->exitCallbackFunction();
}

void HighScoreScreen::exitCallbackFunction() const
{
	SceneLoader::getInstance().loadScene("MainMenuScreen", "", true);
}

void HighScoreScreen::setParent() {}