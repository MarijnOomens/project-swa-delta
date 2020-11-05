#include "MainMenu.h"

MainMenu::MainMenu() 
{
	this->textures.try_emplace("mainmenu", "Assets/mainmenu.png");
	this->textures.try_emplace("button_play", "Assets/button_play.png");
	this->textures.try_emplace("button_credits", "Assets/button_credits.png");
	this->textures.try_emplace("button_exit", "Assets/button_exit.png");

	text = "Delta Dungeons";
	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("mainmenu");
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(gc);

	// Play button
	std::vector<std::string> possibleButtonTexPlay = { "button_play" };
	std::shared_ptr<Button> playButton = std::make_shared<Button>(500, 430, possibleButtonTexPlay);
	this->components.emplace_back(playButton);

	// Credits button
	std::vector<std::string> possibleButtonTexCredits = { "button_credits" };
	std::shared_ptr<Button> creditsButton = std::make_shared<Button>(500, 560, possibleButtonTexCredits);
	this->components.emplace_back(creditsButton);

	// Exit button
	std::vector<std::string> possibleButtonTexExit = { "button_exit" };
	std::shared_ptr<Button> exitButton = std::make_shared<Button>(500, 690, possibleButtonTexExit);
	this->components.emplace_back(exitButton);
}

MainMenu::~MainMenu() {}

void MainMenu::startGame() {}
void MainMenu::openCreditScreen() {}
void MainMenu::closeScreen() {}
