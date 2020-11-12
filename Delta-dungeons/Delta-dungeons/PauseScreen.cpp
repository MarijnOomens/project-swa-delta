#include "PauseScreen.h"

PauseScreen::PauseScreen() 
{
	this->textures.try_emplace("pause", "Assets/Pause_filter.png");
	this->textures.try_emplace("button_help", "Assets/button_help.png");
	this->textures.try_emplace("button_save", "Assets/button_save.png");
	this->fonts.try_emplace("comic", "Assets/comic.ttf");

	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("pause");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	std::vector<std::string> buttonHelp = { "button_help" };
	std::unique_ptr<Button> helpButton = std::make_unique<Button>(512, 400, buttonHelp, staticOpenHelpCallbackFunction, this);
	this->components.emplace_back(std::move(helpButton));

	std::vector<std::string> buttonSave = { "button_save" };
	std::unique_ptr<Button> saveButton = std::make_unique<Button>(512, 600, buttonSave, staticSaveCallbackFunction, this);
	this->components.emplace_back(std::move(saveButton));

	std::vector<std::string> buttonExit = { "button_exit" };
	std::unique_ptr<Button> exitButton = std::make_unique<Button>(512, 800, buttonExit, staticExitCallbackFunction, this);
	this->components.emplace_back(std::move(exitButton));

	Colour color = { 255, 255, 255, 255 };
	std::unique_ptr<TextComponent> creditsText = std::make_unique<TextComponent>("Pause", "comic", color, 64);
	creditsText->transform.position = { 530, 200 };
	this->components.emplace_back(std::move(creditsText));
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

void PauseScreen::saveCallbackFunction() const {}

void PauseScreen::staticExitCallbackFunction(const void* p) 
{
	((PauseScreen*)p)->exitCallbackFunction();
}

void PauseScreen::exitCallbackFunction() const
{
	SceneLoader::getInstance().loadScene("MainMenu", "", true);
}