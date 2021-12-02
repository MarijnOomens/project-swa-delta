#include "LoadSaveScreen.h"

LoadSaveScreen::LoadSaveScreen()
{
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("load_save");
	gc->isScreen = true;
	gc->imageDimensions = { 2560, 1440 };
	this->components.emplace_back(std::move(gc));

	Colour colour = { 255, 255, 255, 255 };

	std::unique_ptr<TextComponent> loadSaveText = std::make_unique<TextComponent>("Load a save file", "joystix", colour, 64);
	loadSaveText->transform.position = { 900, 40 };
	this->components.emplace_back(std::move(loadSaveText));

	std::vector<std::string> possibleButtonTexNew = { "button_new", "button_new_hover" };
	std::unique_ptr<Button> newButton = std::make_unique<Button>(1150, 500, possibleButtonTexNew, staticNewCallbackFunction, this);
	this->components.emplace_back(std::move(newButton));

	std::vector<std::string> possibleButtonTexLoad = { "button_continue", "button_continue_hover" };
	std::unique_ptr<Button> load1Button = std::make_unique<Button>(1150, 700, possibleButtonTexLoad, staticLoadCallbackFunction, this);
	this->components.emplace_back(std::move(load1Button));

	std::vector<std::string> possibleButtonTexExit = { "button_back", "button_back_hover" };
	std::unique_ptr<Button> exitButton = std::make_unique<Button>(1150, 1100, possibleButtonTexExit, staticBackCallbackFunction, this);
	this->components.emplace_back(std::move(exitButton));
}

void LoadSaveScreen::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED)
	{
		if (keyCode == KeyCodes::KEY_BACKSPACE)
		{
			SceneLoader::getInstance().loadPreviousScene();
		}
	}
}

void LoadSaveScreen::staticNewCallbackFunction(const void* p)
{
	((LoadSaveScreen*)p)->newCallbackFunction();
}

void LoadSaveScreen::newCallbackFunction() const 
{
	GameState::getInstance().reset();
	GameState::getInstance().save();
	GameState::getInstance().load();
	SceneLoader::getInstance().loadScene(SceneLoader::getInstance().getCurrentLevel(), "", true, true);
}

void LoadSaveScreen::staticLoadCallbackFunction(const void* p)
{
	((LoadSaveScreen*)p)->loadCallbackFunction();
}

void LoadSaveScreen::loadCallbackFunction() const
{
	GameState::getInstance().load();
	SceneLoader::getInstance().loadScene(SceneLoader::getInstance().getCurrentLevel(), "", true, true);
}

void LoadSaveScreen::staticBackCallbackFunction(const void* p)
{
	((LoadSaveScreen*)p)->backCallbackFunction();
}

void LoadSaveScreen::backCallbackFunction() const
{
	SceneLoader::getInstance().loadPreviousScene();
}