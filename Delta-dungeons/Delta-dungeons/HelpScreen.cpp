#include "HelpScreen.h"

HelpScreen::HelpScreen()
{
	this->textures.try_emplace("help", "Assets/help-scherm.png");


	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("help");
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(gc);


}

HelpScreen::~HelpScreen()
{

}

void HelpScreen::closeScreen() {}