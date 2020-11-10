#include "HelpScreen.h"

HelpScreen::HelpScreen()
{
	this->textures.try_emplace("help", "Assets/help.png");
	this->fonts.try_emplace("comic", "Assets/comic.ttf");


	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("help");
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(gc);

	Colour color = { 0, 0, 0, 255 };

	std::shared_ptr<TextComponent> helpText = std::make_shared<TextComponent>("Help screen", "comic", color, 64);
	helpText->transform.position = { 450, 20 };
	this->components.emplace_back(helpText);

	std::shared_ptr<TextComponent> helpMove = std::make_shared<TextComponent>("Use arrow keys or 'W', 'A', 'S' and 'D' to move your character.", "comic", color, 32);
	helpMove->transform.position = { 100, 170 };
	this->components.emplace_back(helpMove);

	std::shared_ptr<TextComponent> helpInteract = std::make_shared<TextComponent>("Use 'E' to interact.", "comic", color, 32);
	helpInteract->transform.position = { 100, 320 };
	this->components.emplace_back(helpInteract);

	std::shared_ptr<TextComponent> helpBack = std::make_shared<TextComponent>("Press BACKSPACE to go back to the main menu.", "comic", color, 32);
	helpBack->transform.position = { 100, 470 };
	this->components.emplace_back(helpBack);

	std::vector<std::string> possibleButtonTexExit = { "button_exit" };
	std::shared_ptr<Button> exitButton = std::make_shared<Button>(500, 560, possibleButtonTexExit, staticBackCallbackFunction, this);
	this->components.emplace_back(exitButton);
}

HelpScreen::~HelpScreen() {}

void HelpScreen::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED)
	{
		if (keyCode == KeyCodes::KEY_BACKSPACE)
		{
			SceneLoader::getInstance().loadPreviousScene();
		}
	}
}

void HelpScreen::staticBackCallbackFunction(void* p)
{
	((HelpScreen*)p)->backCallbackFunction();
}

void HelpScreen::backCallbackFunction()
{
	SceneLoader::getInstance().loadPreviousScene();
}