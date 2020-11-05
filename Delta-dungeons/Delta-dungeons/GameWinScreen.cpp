#include "GameWinScreen.h"

GameWinScreen::GameWinScreen()
{
	this->textures.try_emplace("gamewin", "Assets/gamewin.png");
	this->textures.try_emplace("button_mainmenu", "Assets/button_exit.png");
	this->fonts.try_emplace("comic", "Assets/comic.ttf");


	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("gamewin");
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(gc);

	// Main menu button
	std::vector<std::string> possibleButtonTexMainMenu = { "button_mainmenu" };
	std::shared_ptr<Button> mainMenuButton = std::make_shared<Button>(500, 750, possibleButtonTexMainMenu);
	this->components.emplace_back(mainMenuButton);

	Colour color = { 0, 0, 0, 255 };
	std::shared_ptr<TextComponent> gameWinText = std::make_shared<TextComponent>("GAME COMPLETED", "comic", color, 64);
	gameWinText->transform.position = { 400, 300 };
	this->components.emplace_back(gameWinText);
}

GameWinScreen::~GameWinScreen() {}

void GameWinScreen::closeScreen() {}