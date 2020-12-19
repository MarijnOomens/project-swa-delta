#include "GameWinScreen.h"

GameWinScreen::GameWinScreen()
{
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("game_win");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	// Next button
	std::vector<std::string> possibleButtonTexNext = { "button_next" };
	std::shared_ptr<Button> nextButton = std::make_shared<Button>(512, 750, possibleButtonTexNext, staticNextCallbackFunction, this);
	this->components.emplace_back(nextButton);

	Colour color = { 0, 0, 0, 255 };
	std::shared_ptr<TextComponent> gameWinText = std::make_shared<TextComponent>("GAME COMPLETED", "joystix", color, 64);
	gameWinText->transform.position = { 400, 300 };
	this->components.emplace_back(gameWinText);
}

void GameWinScreen::start()
{
	AudioUtilities::getInstance().playAudio("credits", true);
}

void GameWinScreen::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED)
	{
		if (keyCode == KeyCodes::KEY_BACKSPACE)
		{
			SceneLoader::getInstance().loadPreviousScene();
		}
	}
}

void GameWinScreen::staticNextCallbackFunction(const void* p)
{
	((GameWinScreen*)p)->nextCallbackFunction();
}

void GameWinScreen::nextCallbackFunction() const
{
	SceneLoader::getInstance().loadScene("HighScoreScreen", "", true);
}