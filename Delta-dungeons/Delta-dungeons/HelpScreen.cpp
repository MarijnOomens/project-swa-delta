#include "HelpScreen.h"

HelpScreen::HelpScreen()
{
	// background
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("help");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	// npc
	auto npcGc = std::make_unique<GraphicsComponent>();
	npcGc->setTexture("npc_icon");
	npcGc->isScreen = true;
	npcGc->imageDimensions = { 32, 32 };
	npcGc->transform.position = { 1075, 180 };
	npcGc->transform.scale = { 2, 2 };
	this->components.emplace_back(std::move(npcGc));

	// runningshoes
	auto rsGc = std::make_unique<GraphicsComponent>();
	rsGc->setTexture("running_shoes_icon");
	rsGc->isScreen = true;
	rsGc->imageDimensions = { 32, 32 };
	rsGc->transform.position = { 1075, 230 };
	rsGc->transform.scale = { 2, 2 };
	this->components.emplace_back(std::move(rsGc));

	// pokeball
	auto pbGc = std::make_unique<GraphicsComponent>();
	pbGc->setTexture("pokeball_icon");
	pbGc->isScreen = true;
	pbGc->imageDimensions = { 32, 32 };
	pbGc->transform.position = { 1075, 280 };
	pbGc->transform.scale = { 2, 2 };
	this->components.emplace_back(std::move(pbGc));

	// berry
	auto bGc = std::make_unique<GraphicsComponent>();
	bGc->setTexture("berry_icon");
	bGc->isScreen = true;
	bGc->imageDimensions = { 32, 32 };
	bGc->transform.position = { 1075, 330 };
	bGc->transform.scale = { 2, 2 };
	this->components.emplace_back(std::move(bGc));

	Colour white = { 255, 255, 255, 255 };
	Colour black = { 0, 0, 0, 255 };

	std::unique_ptr<TextComponent> helpText = std::make_unique<TextComponent>("Help screen", "joystix", white, 64);
	helpText->transform.position = { 370, 20 };
	this->components.emplace_back(std::move(helpText));

	std::unique_ptr<TextComponent> helpMove = std::make_unique<TextComponent>("W, A, S, D or ARROW KEYS: Move character UP, LEFT, DOWN, RIGHT", "joystix", black, 19);
	helpMove->transform.position = { 125, 150 };
	this->components.emplace_back(std::move(helpMove));

	std::unique_ptr<TextComponent> helpInteract = std::make_unique<TextComponent>("E: Interact with NPCs, Items & Puzzles", "joystix", black, 19);
	helpInteract->transform.position = { 125, 200 };
	this->components.emplace_back(std::move(helpInteract));

	std::unique_ptr<TextComponent> helpRun = std::make_unique<TextComponent>("Q: Toggle Running Shoes", "joystix", black, 19);
	helpRun->transform.position = { 125, 250 };
	this->components.emplace_back(std::move(helpRun));

	std::unique_ptr<TextComponent> helpThrowPokeball = std::make_unique<TextComponent>("C: Throw Pokeball", "joystix", black, 19);
	helpThrowPokeball->transform.position = { 125, 300 };
	this->components.emplace_back(std::move(helpThrowPokeball));

	std::unique_ptr<TextComponent> helpBerry = std::make_unique<TextComponent>("B: Eat Berry", "joystix", black, 19);
	helpBerry->transform.position = { 125, 350 };
	this->components.emplace_back(std::move(helpBerry));

	std::unique_ptr<TextComponent> helpPause = std::make_unique<TextComponent>("ESCAPE: Pause Game", "joystix", black, 19);
	helpPause->transform.position = { 125, 400 };
	this->components.emplace_back(std::move(helpPause));

	std::unique_ptr<TextComponent> helpBack = std::make_unique<TextComponent>("BACKSPACE: Switch to previous screen", "joystix", black, 19);
	helpBack->transform.position = { 125, 450 };
	this->components.emplace_back(std::move(helpBack));

	std::unique_ptr<TextComponent> helpBreak = std::make_unique<TextComponent>("----------------------------------------------------------------", "joystix", black, 19);
	helpBreak->transform.position = { 127, 500 };
	this->components.emplace_back(std::move(helpBreak));

	std::unique_ptr<TextComponent> helpObjective = std::make_unique<TextComponent>("Welcome to Delta Dungeons, a game about exploration, puzzles and", "joystix", black, 18);
	helpObjective->transform.position = { 125, 530 };
	this->components.emplace_back(std::move(helpObjective));

	std::unique_ptr<TextComponent> helpObjective2 = std::make_unique<TextComponent>("catching Pokemon. The objective is to catch Pokemon in order to", "joystix", black, 18);
	helpObjective2->transform.position = { 125, 550 };
	this->components.emplace_back(std::move(helpObjective2));

	std::unique_ptr<TextComponent> helpObjective3 = std::make_unique<TextComponent>("increase your score, whilst solving mindbreaking puzzles. Be warned,", "joystix", black, 18);
	helpObjective3->transform.position = { 125, 570 };
	this->components.emplace_back(std::move(helpObjective3));

	std::unique_ptr<TextComponent> helpObjective4 = std::make_unique<TextComponent>("the Pokemon will fight back if you come too close. Explore your way", "joystix", black, 18);
	helpObjective4->transform.position = { 125, 590 };
	this->components.emplace_back(std::move(helpObjective4));

	std::unique_ptr<TextComponent> helpObjective5 = std::make_unique<TextComponent>("through different areas in order to meet someone special and win", "joystix", black, 18);
	helpObjective5->transform.position = { 125, 610 };
	this->components.emplace_back(std::move(helpObjective5));

	std::unique_ptr<TextComponent> helpObjective6 = std::make_unique<TextComponent>("the game ...", "joystix", black, 18);
	helpObjective6->transform.position = { 125, 630 };
	this->components.emplace_back(std::move(helpObjective6));

	std::vector<std::string> possibleButtonTexExit = { "button_back", "button_back_hover" };
	std::unique_ptr<Button> exitButton = std::make_unique<Button>(512, 850, possibleButtonTexExit, staticBackCallbackFunction, this);
	this->components.emplace_back(std::move(exitButton));

}

void HelpScreen::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)
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