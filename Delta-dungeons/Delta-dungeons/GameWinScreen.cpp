#include "GameWinScreen.h"

GameWinScreen::GameWinScreen()
{
	this->textures.try_emplace("game_win", "Assets/Menu/Game-Win/background.png");
	this->textures.try_emplace("button_exit", "Assets/Menu/Button/button-exit.png");
	this->fonts.try_emplace("joystix", "Assets/Font/joystix.ttf");


	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("game_win");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	// Main menu button
	std::vector<std::string> possibleButtonTexMainMenu = { "button_exit" };
	std::shared_ptr<Button> mainMenuButton = std::make_shared<Button>(512, 750, possibleButtonTexMainMenu, staticExitCallbackFunction, this);
	this->components.emplace_back(mainMenuButton);

	Colour color = { 0, 0, 0, 255 };
	std::shared_ptr<TextComponent> gameWinText = std::make_shared<TextComponent>("GAME COMPLETED", "joystix", color, 64);
	gameWinText->transform.position = { 400, 300 };
	this->components.emplace_back(gameWinText);
}

void GameWinScreen::staticExitCallbackFunction(const void* p)
{
	((GameWinScreen*)p)->exitCallbackFunction();
}

void GameWinScreen::exitCallbackFunction() const
{
	SceneLoader::getInstance().loadScene("MainMenu", "", true);
}
