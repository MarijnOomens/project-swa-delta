#include "Creditscreen.h"
/// <summary>
/// This class creates the credits, exitbutton and font and saves them in the components list as a graphicscomponent.
/// </summary>

CreditScreen::CreditScreen()
{
	gc = std::make_unique<GraphicsComponent>();
	gc->isScreen = true;
	gc->setTexture("credits");
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	std::vector<std::string> possibleButtonTexExit = { "button_back" };
	std::unique_ptr<Button> exitButton = std::make_unique<Button>(512, 850, possibleButtonTexExit, staticBackCallbackFunction, this);
	this->components.emplace_back(std::move(exitButton));

	Colour color = { 0, 0, 0, 255 };
	std::unique_ptr<TextComponent> creditsText = std::make_unique<TextComponent>("Credits", "joystix", color, 64);
	creditsText->transform.position = { 470, 225 };
	this->components.emplace_back(std::move(creditsText));

	color = { 255, 0, 0, 255 };
	std::unique_ptr<TextComponent> creditsText1 = std::make_unique<TextComponent>("Ymke", "joystix", color, 32);
	creditsText1->transform.position = { 570, 325 };
	this->components.emplace_back(std::move(creditsText1));

	color = { 0, 207, 3, 255 };
	std::unique_ptr<TextComponent> creditsText2 = std::make_unique<TextComponent>("Marijn", "joystix", color, 32);
	creditsText2->transform.position = { 570, 375 };
	this->components.emplace_back(std::move(creditsText2));

	color = { 0, 0, 255, 255 };
	std::unique_ptr<TextComponent> creditsText3 = std::make_unique<TextComponent>("Robin", "joystix", color, 32);
	creditsText3->transform.position = { 570, 425 };
	this->components.emplace_back(std::move(creditsText3));

	color = { 210, 105, 30, 255 };
	std::unique_ptr<TextComponent> creditsText4 = std::make_unique<TextComponent>("Raymond", "joystix", color, 32);
	creditsText4->transform.position = { 570, 475 };
	this->components.emplace_back(std::move(creditsText4));

	color = { 148, 0, 211, 255 };
	std::unique_ptr<TextComponent> creditsText5 = std::make_unique<TextComponent>("Yoran", "joystix", color, 32);
	creditsText5->transform.position = { 570, 525 };
	this->components.emplace_back(std::move(creditsText5));

	color = { 255,215,0, 255 };
	std::unique_ptr<TextComponent> creditsText6 = std::make_unique<TextComponent>("Tristan", "joystix", color, 32);
	creditsText6->transform.position = { 570, 575 };
	this->components.emplace_back(std::move(creditsText6));

	color = { 0,0,0, 255 };
	std::unique_ptr<TextComponent> creditsText7 = std::make_unique<TextComponent>("Bob", "joystix", color, 32);
	creditsText7->transform.position = { 570, 625 };
	this->components.emplace_back(std::move(creditsText7));
}

void CreditScreen::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED)
	{
		if (keyCode == KeyCodes::KEY_BACKSPACE)
		{
			AudioUtilities::getInstance().playAudio("touch", true);
			SceneLoader::getInstance().loadPreviousScene();
		}
	}
}

void CreditScreen::start()
{
	AudioUtilities::getInstance().playAudio("mii", true);
}

void CreditScreen::staticBackCallbackFunction(const void* p) 
{
	((CreditScreen*)p)->backCallbackFunction();
}

void CreditScreen::backCallbackFunction() const
{
	AudioUtilities::getInstance().playAudio("touch", true);
	SceneLoader::getInstance().loadPreviousScene();
}