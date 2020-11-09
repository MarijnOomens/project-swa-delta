#include "Creditscreen.h"
/// <summary>
/// This class creates the credits, exitbutton and font and saves them in the components list as a graphicscomponent.
/// </summary>
 
CreditScreen::CreditScreen()
{
	this->textures.try_emplace("credits", "Assets/screen-components/credit-scherm-design/creditscreen-2.png");
	this->textures.try_emplace("button_exit", "Assets/screen-components/button-designs/pastels/button-exit-1.png");
	this->fonts.try_emplace("comic", "Assets/comic.ttf");

	gc = std::make_shared<GraphicsComponent>();
	gc->isScreen = true;
	gc->setTexture("credits");
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(gc);

	std::vector<std::string> possibleButtonTexExit = { "button_exit" };
	std::shared_ptr<Button> exitButton = std::make_shared<Button>(500, 800, possibleButtonTexExit);
	this->components.emplace_back(exitButton);

	Colour color = { 0, 0, 0, 255 };
	std::shared_ptr<TextComponent> creditsText = std::make_shared<TextComponent>("Credits", "comic", color, 64);
	creditsText->transform.position = { 530, 225 };
	this->components.emplace_back(creditsText);

	color = { 255, 0, 0, 255 };
	std::shared_ptr<TextComponent> creditsText1 = std::make_shared<TextComponent>("Ymke", "comic", color, 32);
	creditsText1->transform.position = { 550, 325 };
	this->components.emplace_back(creditsText1);

	color = { 0, 207, 3, 255 };
	std::shared_ptr<TextComponent> creditsText2 = std::make_shared<TextComponent>("Marijn", "comic", color, 32);
	creditsText2->transform.position = { 550, 375 };
	this->components.emplace_back(creditsText2);

	color = { 0, 0, 255, 255 };
	std::shared_ptr<TextComponent> creditsText3 = std::make_shared<TextComponent>("Robin", "comic", color, 32);
	creditsText3->transform.position = { 550, 425 };
	this->components.emplace_back(creditsText3);

	color = { 210, 105, 30, 255 };
	std::shared_ptr<TextComponent> creditsText4 = std::make_shared<TextComponent>("Raymond", "comic", color, 32);
	creditsText4->transform.position = { 550, 475 };
	this->components.emplace_back(creditsText4);

	color = { 148, 0, 211, 255 };
	std::shared_ptr<TextComponent> creditsText5 = std::make_shared<TextComponent>("Yoran", "comic", color, 32);
	creditsText5->transform.position = { 550, 525 };
	this->components.emplace_back(creditsText5);

	color = { 0, 0, 0, 255 };
	std::shared_ptr<TextComponent> creditsText6 = std::make_shared<TextComponent>("Tristan", "comic", color, 32);
	creditsText6->transform.position = { 550, 575 };
	this->components.emplace_back(creditsText6);
}

CreditScreen::~CreditScreen() {}

void CreditScreen::closeScreen()
{

}

void CreditScreen::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED)
	{
		if (keyCode == KeyCodes::KEY_BACKSPACE)
		{
			SceneLoader::getInstance().loadPreviousScene();
		}
	}
}