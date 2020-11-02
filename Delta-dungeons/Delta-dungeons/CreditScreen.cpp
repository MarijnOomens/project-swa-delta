#include "Creditscreen.h"
/// <summary>
/// This class creates the credits, exitbutton and font and saves them in the components list as a graphicscomponent.
/// </summary>
 
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

	Colour color = { 0, 0, 0, 255 };
	std::shared_ptr<TextComponent> creditsText = std::make_shared<TextComponent>("Credits", "comic", color, 64);
	creditsText->transform.position = { 530, 200 };
	this->components.emplace_back(creditsText);

	color = { 255, 0, 0, 255 };
	std::shared_ptr<TextComponent> creditsText1 = std::make_shared<TextComponent>("Ymke", "comic", color, 32);
	creditsText1->transform.position = { 550, 300 };
	this->components.emplace_back(creditsText1);

	color = { 0, 207, 3, 255 };
	std::shared_ptr<TextComponent> creditsText2 = std::make_shared<TextComponent>("Marijn", "comic", color, 32);
	creditsText2->transform.position = { 550, 350 };
	this->components.emplace_back(creditsText2);
}

CreditScreen::~CreditScreen() {}

void CreditScreen::closeScreen()
{

}