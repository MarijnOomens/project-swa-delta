#include "MainMenuScene.h"

MainMenuScene::MainMenuScene()
{
	this->name = "MainMenuScreen";
	this->setBehaviourObjects({ std::make_shared<MainMenu>() });
	this->setTexture("main_menu", "Assets/Menu/Main-Menu/background.png");
	this->setTexture("button_play", "Assets/Menu/Button/button-play.png");
	this->setTexture("button_play_hover", "Assets/Menu/Button/button-play-hover.png");
	this->setTexture("button_credits", "Assets/Menu/Button/button-credits.png");
	this->setTexture("button_credits_hover", "Assets/Menu/Button/button-credits-hover.png");
	this->setTexture("button_help", "Assets/Menu/Button/button-help.png");
	this->setTexture("button_help_hover", "Assets/Menu/Button/button-help-hover.png");
	this->setTexture("button_exit", "Assets/Menu/Button/button-exit.png");
	this->setTexture("button_exit_hover", "Assets/Menu/Button/button-exit-hover.png");
	this->setTexture("ad", "Assets/Advertisement/Advertisement.png");
	this->setFont("joystix", "Assets/Font/joystix.ttf");
	this->setBeat("touch", "Assets/Audio/touch.ogg");
}