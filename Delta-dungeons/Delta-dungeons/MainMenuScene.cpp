#include "MainMenuScene.h"

MainMenuScene::MainMenuScene()
{
	this->name = "MainMenuScreen";
	this->setBehaviourObjects({ std::make_shared<MainMenu>() });
	this->setTexture("main_menu", "Assets/Menu/Main-Menu/background.png");
	this->setTexture("button_play", "Assets/Menu/Button/button-play.png");
	this->setTexture("button_credits", "Assets/Menu/Button/button-credits.png");
	this->setTexture("button_help", "Assets/Menu/Button/button-help.png");
	this->setTexture("button_exit", "Assets/Menu/Button/button-exit.png");
	this->setTexture("ad", "Assets/Advertisement/Advertisement.png");
	this->setFont("joystix", "Assets/Font/joystix.ttf");
	this->setBeat("touch", "Assets/Audio/touch.ogg");
}