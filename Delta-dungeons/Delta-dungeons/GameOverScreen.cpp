#include "GameOverScreen.h"

GameOverScreen::GameOverScreen()
{
	this->textures.try_emplace("gameover", "Assets/gameover.png");
	this->textures.try_emplace("button_mainmenu", "Assets/button_exit.png");
	this->fonts.try_emplace("comic", "Assets/comic.ttf");


	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("gameover");
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(gc);

	// Main menu button
	std::vector<std::string> possibleButtonTexMainMenu = { "button_mainmenu" };
	std::shared_ptr<Button> mainMenuButton = std::make_shared<Button>(500, 750, possibleButtonTexMainMenu);
	this->components.emplace_back(mainMenuButton);

	Colour color = { 255, 255, 255, 255 };
	std::shared_ptr<TextComponent> gameOverText = std::make_shared<TextComponent>("GAME OVER", "comic", color, 64);
	gameOverText->transform.position = { 450, 500 };
	this->components.emplace_back(gameOverText);
}

GameOverScreen::~GameOverScreen()
{

}

void GameOverScreen::closeScreen()
{

}

void GameOverScreen::restartGame()
{

}
