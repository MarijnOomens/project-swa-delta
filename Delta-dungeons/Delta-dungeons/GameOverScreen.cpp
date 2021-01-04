#include "GameOverScreen.h"

GameOverScreen::GameOverScreen()
{
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("game_over");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	Colour colour = { 255, 255, 255, 255 };

	std::shared_ptr<TextComponent> gameOverText = std::make_shared<TextComponent>("GAME OVER", "joystix", colour, 64);
	gameOverText->transform.position = { 400, 200 };
	this->components.emplace_back(gameOverText);

	std::vector<std::string> possibleButtonTexNext = { "button_next", "button_next_hover" };
	std::shared_ptr<Button> nextButton = std::make_shared<Button>(512, 750, possibleButtonTexNext, staticNextCallbackFunction, this);
	this->components.emplace_back(nextButton);
}

void GameOverScreen::staticNextCallbackFunction(const void* p)
{
	((GameOverScreen*)p)->nextCallbackFunction();
}

void GameOverScreen::nextCallbackFunction() const
{
	SceneLoader::getInstance().loadScene("HighScoreScreen", "", true, false);
}