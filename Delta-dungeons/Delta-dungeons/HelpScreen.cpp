#include "HelpScreen.h"

HelpScreen::HelpScreen()
{
	this->textures.try_emplace("help", "Assets/help.png");
	this->fonts.try_emplace("joystix", "Assets/joystix.ttf");

	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("help");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	Colour color = { 0, 0, 0, 255 };

	std::unique_ptr<TextComponent> helpText = std::make_unique<TextComponent>("Help screen", "joystix", color, 64);
	helpText->transform.position = { 390, 20 };
	this->components.emplace_back(std::move(helpText));

	std::unique_ptr<TextComponent> helpMove = std::make_unique<TextComponent>("Use arrow keys or W, A, S and D to move your character.", "joystix", color, 25);
	helpMove->transform.position = { 50, 120 };
	this->components.emplace_back(std::move(helpMove));

	std::unique_ptr<TextComponent> helpInteract = std::make_unique<TextComponent>("Use E to interact.", "joystix", color, 25);
	helpInteract->transform.position = { 50, 200 };
	this->components.emplace_back(std::move(helpInteract));

	std::unique_ptr<TextComponent> helpBack = std::make_unique<TextComponent>("Press BACKSPACE to go back to the main menu.", "joystix", color, 25);
	helpBack->transform.position = { 50, 280 };
	this->components.emplace_back(std::move(helpBack));

	std::unique_ptr<TextComponent> helpFps = std::make_unique<TextComponent>("Press TAB to toggle the FPS counter in the upper right corner in-game.", "joystix", color, 25);
	helpFps->transform.position = { 50, 360 };
	this->components.emplace_back(std::move(helpFps));

	std::unique_ptr<TextComponent> helpGameSpeed = std::make_unique<TextComponent>("Press , to decrease FPS. Press . to increase FPS. Press / to reset FPS to 60.", "joystix", color, 25);
	helpGameSpeed->transform.position = { 50, 440 };
	this->components.emplace_back(std::move(helpGameSpeed));

	std::unique_ptr<TextComponent> helpGameOver = std::make_unique<TextComponent>("Game over is triggered when the player is out of hearts. This can be done by walking into any Pok�mon.", "joystix", color, 25);
	helpGameOver->transform.position = { 50, 520 };
	this->components.emplace_back(std::move(helpGameOver));

	std::vector<std::string> possibleButtonTexExit = { "button_exit" };
	std::unique_ptr<Button> exitButton = std::make_unique<Button>(500, 720, possibleButtonTexExit, staticBackCallbackFunction, this);
	this->components.emplace_back(std::move(exitButton));
}

void HelpScreen::handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED)
	{
		if (keyCode == KeyCodes::KEY_BACKSPACE)
		{
			SceneLoader::getInstance().loadPreviousScene();
		}
	}
}

void HelpScreen::staticBackCallbackFunction(const void* p)
{
	((HelpScreen*)p)->backCallbackFunction();
}

void HelpScreen::backCallbackFunction() const
{
	SceneLoader::getInstance().loadPreviousScene();
}