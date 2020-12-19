#include "MainMenu.h"

MainMenu::MainMenu() 
{
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("main_menu");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	Colour color = { 255, 203, 5, 255 };
	std::unique_ptr<TextComponent> creditsText = std::make_unique<TextComponent>("DELTA DUNGEONS", "joystix", color, 72);
	creditsText->transform.position = { 230, 50 };
	this->components.emplace_back(std::move(creditsText));

	// Play button
	std::vector<std::string> possibleButtonTexPlay = { "button_play" };
	std::unique_ptr<Button> playButton = std::make_unique<Button>(512, 230, possibleButtonTexPlay, staticOpenGameCallbackFunction, this);
	this->components.emplace_back(std::move(playButton));

	// Credits button
	std::vector<std::string> possibleButtonTexCredits = { "button_credits" };
	std::unique_ptr<Button> creditsButton = std::make_unique<Button>(512, 360, possibleButtonTexCredits, staticOpenCreditsCallbackFunction, this);
	this->components.emplace_back(std::move(creditsButton));

	// Help button
	std::vector<std::string> possibleButtonTexHelp = { "button_help" };
	std::unique_ptr<Button> helpButton = std::make_unique<Button>(512, 490, possibleButtonTexHelp, staticOpenHelpCallbackFunction, this);
	this->components.emplace_back(std::move(helpButton));

	// Exit button
	std::vector<std::string> possibleButtonTexExit = { "button_exit" };
	std::unique_ptr<Button> exitButton = std::make_unique<Button>(512, 620, possibleButtonTexExit, staticExitCallbackFunction, this);
	this->components.emplace_back(std::move(exitButton));

	// Advertisement
	std::vector<std::string> adTexture = { "ad" };
	std::unique_ptr<Advertisement> adButton = std::make_unique<Advertisement>(870, 890, adTexture);
	this->components.emplace_back(std::move(adButton));
}

void MainMenu::start()
{
	AudioUtilities::getInstance().playAudio("touch", true);
}

void MainMenu::handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) {}

void MainMenu::staticOpenGameCallbackFunction(const void* p) 
{
	((MainMenu*)p)->openGameCallbackFunction();
}

void MainMenu::openGameCallbackFunction() const
{
	SceneLoader::getInstance().loadScene("LoadSaveScreen", "MainMenuScreen", true);
}

void MainMenu::staticOpenCreditsCallbackFunction(const void* p) 
{
	((MainMenu*)p)->openCreditsCallbackFunction();
}

void MainMenu::openCreditsCallbackFunction() const
{
	SceneLoader::getInstance().loadScene("CreditScreen", "MainMenuScreen", true);
}

void MainMenu::staticOpenHelpCallbackFunction(const void* p)
{
	((MainMenu*)p)->openHelpCallbackFunction();
}

void MainMenu::openHelpCallbackFunction() const
{
	SceneLoader::getInstance().loadScene("HelpScreen", "MainMenuScreen", true);
}

void MainMenu::staticExitCallbackFunction(const void* p) 
{
	((MainMenu*)p)->exitCallbackFunction();
}

void MainMenu::exitCallbackFunction() const
{
	SceneLoader::getInstance().quitGame();
}