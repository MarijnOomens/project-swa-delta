#include "PauseScreen.h"

PauseScreen::PauseScreen()
{
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("pause");
	gc->isScreen = true;
	gc->imageDimensions = { 2560, 1440 };
	this->components.emplace_back(std::move(gc));

	std::vector<std::string> buttonHelp = { "button_help", "button_help_hover" };
	std::unique_ptr<Button> helpButton = std::make_unique<Button>(1150, 550, buttonHelp, staticOpenHelpCallbackFunction, this);
	this->components.emplace_back(std::move(helpButton));

	std::vector<std::string> buttonSave = { "button_save", "button_save_hover" };
	std::unique_ptr<Button> saveButton = std::make_unique<Button>(1150, 750, buttonSave, staticSaveCallbackFunction, this);
	this->components.emplace_back(std::move(saveButton));

	std::vector<std::string> buttonExit = { "button_exit", "button_exit_hover" };
	std::unique_ptr<Button> exitButton = std::make_unique<Button>(1150, 1100, buttonExit, staticExitCallbackFunction, this);
	this->components.emplace_back(std::move(exitButton));

	Colour colour = { 255, 255, 255, 255 };
	std::unique_ptr<TextComponent> pauseText = std::make_unique<TextComponent>("Pause", "joystix", colour, 64);
	pauseText->transform.position = { 1160, 200 };
	this->components.emplace_back(std::move(pauseText));
}

void PauseScreen::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)
{
}

void PauseScreen::staticOpenHelpCallbackFunction(const void* p)
{
	((PauseScreen*)p)->openHelpCallbackFunction();
}

void PauseScreen::openHelpCallbackFunction() const
{
	SceneLoader::getInstance().addOverlayScene("HelpScreen");
}

void PauseScreen::staticSaveCallbackFunction(const void* p)
{
	((PauseScreen*)p)->saveCallbackFunction();
}

void PauseScreen::saveCallbackFunction() const
{
	AudioUtilities::getInstance().playEffect("save");
	GameState::getInstance().save();
}

void PauseScreen::staticExitCallbackFunction(const void* p)
{
	((PauseScreen*)p)->exitCallbackFunction();
}

void PauseScreen::exitCallbackFunction() const
{
	SceneLoader::getInstance().loadScene("MainMenuScreen", "", true, false);
}