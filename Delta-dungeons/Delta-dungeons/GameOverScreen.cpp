#include "GameOverScreen.h"

GameOverScreen::GameOverScreen()
{
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("game_over");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	// Main menu button
	std::vector<std::string> possibleButtonTexMainMenu = { "button_exit" };
	std::shared_ptr<Button> mainMenuButton = std::make_shared<Button>(512, 750, possibleButtonTexMainMenu, staticExitCallbackFunction, this);
	this->components.emplace_back(mainMenuButton);

	Colour color = { 255, 255, 255, 255 };
	std::shared_ptr<TextComponent> gameOverText = std::make_shared<TextComponent>("GAME OVER", "joystix", color, 64);
	gameOverText->transform.position = { 450, 500 };
	this->components.emplace_back(gameOverText);
}

void GameOverScreen::restartGame() {}

void GameOverScreen::staticExitCallbackFunction(const void* p)
{
	((GameOverScreen*)p)->exitCallbackFunction();
}

void GameOverScreen::exitCallbackFunction() const
{
	SceneLoader::getInstance().loadScene("MainMenuScreen", "", true);
}

void GameOverScreen::setParent() {}