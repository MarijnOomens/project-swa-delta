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
	std::shared_ptr<Button> playButton = std::make_shared<Button>(500, 300, possibleButtonTexPlay, staticOpenGameCallbackFunction, this);
	this->components.emplace_back(playButton);

	// Credits button
	std::vector<std::string> possibleButtonTexCredits = { "button_credits" };
	std::shared_ptr<Button> creditsButton = std::make_shared<Button>(500, 430, possibleButtonTexCredits, staticOpenCreditsCallbackFunction, this);
	this->components.emplace_back(creditsButton);

	// Help button
	std::vector<std::string> possibleButtonTexHelp = { "button_help" };
	std::shared_ptr<Button> helpButton = std::make_shared<Button>(500, 560, possibleButtonTexHelp, staticOpenHelpCallbackFunction, this);
	this->components.emplace_back(helpButton);

	// Exit button
	std::vector<std::string> possibleButtonTexExit = { "button_exit" };
	std::shared_ptr<Button> exitButton = std::make_shared<Button>(500, 690, possibleButtonTexExit, staticExitCallbackFunction, this);
	this->components.emplace_back(exitButton);

	Colour color = { 0, 255, 0, 255 };
	fpsText = std::make_shared<TextComponent>("60", "comic", color, 32);
	fpsText->transform.position = { 1200, 10 };
	components.emplace_back(fpsText);
}

MainMenu::~MainMenu() {}

void MainMenu::startGame() {}
void MainMenu::openCreditScreen() {}

void MainMenu::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos)
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
		else if (keyCode == KeyCodes::KEY_H)
		{
			SceneLoader::getInstance().loadScene("HelpScreen", "MainMenu", false);
		}
	}
}

void MainMenu::staticOpenGameCallbackFunction(void* p) 
{
	((MainMenu*)p)->openGameCallbackFunction();
}

void MainMenu::openGameCallbackFunction() 
{
	SceneLoader::getInstance().loadScene("Level1", "MainMenu", false);
}

void MainMenu::staticOpenCreditsCallbackFunction(void* p) 
{
	((MainMenu*)p)->openCreditsCallbackFunction();
}

void MainMenu::openCreditsCallbackFunction() 
{
	SceneLoader::getInstance().loadScene("CreditsScreen", "MainMenu", false);
}

void MainMenu::staticOpenHelpCallbackFunction(void* p)
{
	((MainMenu*)p)->openHelpCallbackFunction();
}

void MainMenu::openHelpCallbackFunction()
{
	SceneLoader::getInstance().loadScene("HelpScreen", "MainMenu", false);
}

void MainMenu::staticExitCallbackFunction(void* p) 
{
	((MainMenu*)p)->exitCallbackFunction();
}

void MainMenu::exitCallbackFunction() 
{
	SceneLoader::getInstance().quitGame();
}

void MainMenu::update() {
	std::stringstream fpsString;
	fpsString.str(std::to_string(test));
	fpsText->changeText(fpsString.str());
	++test;
}