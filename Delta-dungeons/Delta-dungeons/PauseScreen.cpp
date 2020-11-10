#include "PauseScreen.h"

PauseScreen::PauseScreen() {
	this->textures.try_emplace("pause", "Assets/Pause_filter.png");
	this->textures.try_emplace("button_help", "Assets/button_help.png");
	this->textures.try_emplace("button_save", "Assets/button_save.png");
	this->fonts.try_emplace("comic", "Assets/comic.ttf");

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("pause");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(gc);

	std::vector<std::string> buttonHelp = { "button_help" };
	std::shared_ptr<Button> helpButton = std::make_shared<Button>(512, 400, buttonHelp, staticOpenHelpCallbackFunction, this);
	this->components.emplace_back(helpButton);

	std::vector<std::string> buttonSave = { "button_save" };
	std::shared_ptr<Button> saveButton = std::make_shared<Button>(512, 600, buttonSave, staticSaveCallbackFunction, this);
	this->components.emplace_back(saveButton);

	std::vector<std::string> buttonExit = { "button_exit" };
	std::shared_ptr<Button> exitButton = std::make_shared<Button>(512, 800, buttonExit, staticExitCallbackFunction, this);
	this->components.emplace_back(exitButton);

	Colour color = { 255, 255, 255, 255 };
	std::shared_ptr<TextComponent> creditsText = std::make_shared<TextComponent>("Pause", "comic", color, 64);
	creditsText->transform.position = { 530, 200 };
	this->components.emplace_back(creditsText);
}

PauseScreen::~PauseScreen() {}

void PauseScreen::openHelp() {}

void PauseScreen::saveGame() {}

void PauseScreen::staticOpenHelpCallbackFunction(void* p) 
{
	((PauseScreen*)p)->openHelpCallbackFunction();
}

void PauseScreen::openHelpCallbackFunction() 
{
	SceneLoader::getInstance().addOverlayScene("HelpScreen");
}

void PauseScreen::staticSaveCallbackFunction(void* p) 
{
	((PauseScreen*)p)->saveCallbackFunction();
}

void PauseScreen::saveCallbackFunction() 
{

}
void PauseScreen::staticExitCallbackFunction(void* p) 
{
	((PauseScreen*)p)->exitCallbackFunction();
}

void PauseScreen::exitCallbackFunction() 
{
	SceneLoader::getInstance().loadScene("MainMenu", "Level1", false);
}