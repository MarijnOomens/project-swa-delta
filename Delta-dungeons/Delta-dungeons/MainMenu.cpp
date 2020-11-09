#include "MainMenu.h"

MainMenu::MainMenu() 
{
	this->textures.try_emplace("mainmenu", "Assets/screen-components/mainmenu-designs/mainmenu-2.png");
	this->textures.try_emplace("button_play", "Assets/screen-components/button-designs/pastels/button-play-1.png");
	this->textures.try_emplace("button_credits", "Assets/screen-components/button-designs/pastels/button-credits-1.png");
	this->textures.try_emplace("button_exit", "Assets/screen-components/button-designs/pastels/button-exit-1.png");

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("mainmenu");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(gc);

	// Play button
	std::vector<std::string> possibleButtonTexPlay = { "button_play" };
	std::shared_ptr<Button> playButton = std::make_shared<Button>(500, 300, possibleButtonTexPlay);
	this->components.emplace_back(playButton);

	// Credits button
	std::vector<std::string> possibleButtonTexCredits = { "button_credits" };
	std::shared_ptr<Button> creditsButton = std::make_shared<Button>(500, 430, possibleButtonTexCredits);
	this->components.emplace_back(creditsButton);

	// Help button
	//std::vector<std::string> possibleButtonTexHelp = { "button_help" };
	//std::shared_ptr<Button> helpButton = std::make_shared<Button>(500, 690, possibleButtonTexHelp);
	//this->components.emplace_back(helpButton);

	// Exit button
	std::vector<std::string> possibleButtonTexExit = { "button_exit" };
	std::shared_ptr<Button> exitButton = std::make_shared<Button>(500, 560, possibleButtonTexExit);
	this->components.emplace_back(exitButton);
}

MainMenu::~MainMenu() {}

void MainMenu::startGame() {}
void MainMenu::openCreditScreen() {}

void MainMenu::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED)
	{
		if (keyCode == KeyCodes::KEY_E)
		{
			SceneLoader::getInstance().loadScene("Level1", "MainMenu", false);
		}
		else if (keyCode == KeyCodes::KEY_G)
		{
			SceneLoader::getInstance().loadScene("CreditScreen", "MainMenu", false);
		}
		else if (keyCode == KeyCodes::KEY_BACKSPACE)
		{
			SceneLoader::getInstance().loadPreviousScene();
		}
	}
}

void MainMenu::closeScreen() {}

