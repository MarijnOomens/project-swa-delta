#include "HighScoreScreen.h"

HighScoreScreen::HighScoreScreen()
{
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("high_score");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	// Main menu button
	std::vector<std::string> possibleButtonTexMainMenu = { "button_exit", "button_exit_hover" };
	std::shared_ptr<Button> mainMenuButton = std::make_shared<Button>(512, 750, possibleButtonTexMainMenu, staticExitCallbackFunction, this);
	this->components.emplace_back(mainMenuButton);

	Colour color1 = { 237, 134, 0, 255 };
	beatText = std::make_shared<TextComponent>("", "joystix", color1, 80);
	beatText->transform.position = { 50, 100 };
	this->components.emplace_back(beatText);

	Colour color = { 255, 255, 255, 255 };
	highScoreText = std::make_shared<TextComponent>("HIGH SCORE: " + std::to_string(0), "joystix", color, 64);
	highScoreText->transform.position = { 275, 450 };
	this->components.emplace_back(highScoreText);

	yourScoreText = std::make_shared<TextComponent>("YOUR SCORE: " + std::to_string(0), "joystix", color, 64);
	yourScoreText->transform.position = { 275, 550 };
	this->components.emplace_back(yourScoreText);
}

void HighScoreScreen::staticExitCallbackFunction(const void* p)
{
	((HighScoreScreen*)p)->exitCallbackFunction();
}

void HighScoreScreen::exitCallbackFunction() const
{
	SceneLoader::getInstance().loadScene("MainMenuScreen", "", true, false);
}

void HighScoreScreen::start()
{
	score = GameState::getInstance().getHighScore();
	highScoreText->changeText("HIGH SCORE: " + std::to_string(score));

	int yourScore = GameState::getInstance().getCaughtPokemon();
	yourScoreText->changeText("YOUR SCORE: " + std::to_string(yourScore));

	if (yourScore == score && score != 0)
	{
		beatText->changeText("CONGRATS, YOU BEAT THE HIGH SCORE!");
	}
	else {
		beatText->changeText("");
	}
}