#include "Creditscreen.h"
/// <summary>
/// This class creates the credits, exitbutton and font and saves them in the components list as a graphicscomponent.
/// </summary>

CreditScreen::CreditScreen()
{
	this->textures.try_emplace("credits", "Assets/screen-components/credit-scherm-design/creditscreen-2.png");
	this->textures.try_emplace("button_exit", "Assets/screen-components/button-designs/pastels/button-exit-1.png");
	this->fonts.try_emplace("comic", "Assets/comic.ttf");

	gc = std::make_unique<GraphicsComponent>();
	gc->isScreen = true;
	gc->setTexture("credits");
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	std::vector<std::string> possibleButtonTexExit = { "button_exit" };
	std::unique_ptr<Button> exitButton = std::make_unique<Button>(500, 800, possibleButtonTexExit, staticBackCallbackFunction, this);
	this->components.emplace_back(std::move(exitButton));

	Colour color = { 0, 0, 0, 255 };
	std::unique_ptr<TextComponent> creditsText = std::make_unique<TextComponent>("Credits", "comic", color, 64);
	creditsText->transform.position = { 530, 225 };
	this->components.emplace_back(std::move(creditsText));

	color = { 255, 0, 0, 255 };
	std::unique_ptr<TextComponent> creditsText1 = std::make_unique<TextComponent>("Ymke", "comic", color, 32);
	creditsText1->transform.position = { 550, 325 };
	this->components.emplace_back(std::move(creditsText1));

	color = { 0, 207, 3, 255 };
	std::unique_ptr<TextComponent> creditsText2 = std::make_unique<TextComponent>("Marijn", "comic", color, 32);
	creditsText2->transform.position = { 550, 375 };
	this->components.emplace_back(std::move(creditsText2));

	color = { 0, 0, 255, 255 };
	std::unique_ptr<TextComponent> creditsText3 = std::make_unique<TextComponent>("Robin", "comic", color, 32);
	creditsText3->transform.position = { 550, 425 };
	this->components.emplace_back(std::move(creditsText3));

	color = { 210, 105, 30, 255 };
	std::unique_ptr<TextComponent> creditsText4 = std::make_unique<TextComponent>("Raymond", "comic", color, 32);
	creditsText4->transform.position = { 550, 475 };
	this->components.emplace_back(std::move(creditsText4));

	color = { 148, 0, 211, 255 };
	std::unique_ptr<TextComponent> creditsText5 = std::make_unique<TextComponent>("Yoran", "comic", color, 32);
	creditsText5->transform.position = { 550, 525 };
	this->components.emplace_back(std::move(creditsText5));

	color = { 255,215,0, 255 };
	std::unique_ptr<TextComponent> creditsText6 = std::make_unique<TextComponent>("Tristan", "comic", color, 32);
	creditsText6->transform.position = { 550, 575 };
	this->components.emplace_back(std::move(creditsText6));
}

void CreditScreen::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED)
	{
		if (keyCode == KeyCodes::KEY_BACKSPACE)
		{
			SceneLoader::getInstance().loadPreviousScene();
		}
	}
}

void CreditScreen::staticBackCallbackFunction(const void* p) 
{
	((CreditScreen*)p)->backCallbackFunction();
}

void CreditScreen::backCallbackFunction()const
{
	SceneLoader::getInstance().loadPreviousScene();
}