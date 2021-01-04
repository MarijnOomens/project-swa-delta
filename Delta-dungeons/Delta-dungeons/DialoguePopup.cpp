#include "DialoguePopup.h"

DialoguePopup::DialoguePopup(const std::string& dialogue)
{
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("dialogue_box");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 292 };

	this->transform.position = { 5, 700 };
	gc->transform.position = this->transform.position;
	this->components.emplace_back(std::move(gc));

	Colour color = { 255, 255, 255, 255 };
	std::unique_ptr<TextComponent> dialogueText = std::make_unique<TextComponent>(dialogue, "joystix", color, 30);
	dialogueText->transform.position = { 50, 750 };
	this->components.emplace_back(std::move(dialogueText));
}

void DialoguePopup::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED && keyCode == KeyCodes::KEY_E)
	{
		SceneLoader::getInstance().loadPreviousScene();
		DebugUtilities::getInstance().pauseInput();
		GameState::getInstance().setIsInputPaused(false);
	}
}