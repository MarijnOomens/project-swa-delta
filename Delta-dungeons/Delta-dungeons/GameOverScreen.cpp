#include "GameOverScreen.h"

GameOverScreen::GameOverScreen()
{
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("game_over");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	// Next button
	std::vector<std::string> possibleButtonTexNext = { "button_next" };
	std::shared_ptr<Button> nextButton = std::make_shared<Button>(512, 750, possibleButtonTexNext, staticNextCallbackFunction, this);
	this->components.emplace_back(nextButton);

	Colour color = { 255, 255, 255, 255 };
	std::shared_ptr<TextComponent> gameOverText = std::make_shared<TextComponent>("GAME OVER", "joystix", color, 64);
	gameOverText->transform.position = { 450, 500 };
	this->components.emplace_back(gameOverText);
}

void GameOverScreen::staticNextCallbackFunction(const void* p)
{
	((GameOverScreen*)p)->nextCallbackFunction();
}

void GameOverScreen::nextCallbackFunction() const
{
	SceneLoader::getInstance().loadScene("HighScoreScreen", "", true);
}

void GameOverScreen::setParent() {}