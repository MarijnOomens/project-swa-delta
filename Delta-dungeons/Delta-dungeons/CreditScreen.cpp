#include "Creditscreen.h"

CreditScreen::CreditScreen()
{
	this->textures.try_emplace("credits", "Assets/credit-scherm.png");
	this->textures.try_emplace("button_exit", "Assets/button_exit.png");
	this->fonts.try_emplace("comic", "Assets/comic.ttf");

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("credits");
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(gc);

	std::vector<std::string> possibleButtonTexExit = { "button_exit" };
	std::shared_ptr<Button> exitButton = std::make_shared<Button>(512, 800, possibleButtonTexExit);
	this->components.emplace_back(exitButton);

	Colour color = { 255, 255, 255, 255 };
	std::shared_ptr<UIText> creditsText = std::make_shared<UIText>(512, 200, "Credits", color);
	this->components.emplace_back(creditsText);
}

CreditScreen::~CreditScreen() {}

void CreditScreen::closeScreen()
{

}