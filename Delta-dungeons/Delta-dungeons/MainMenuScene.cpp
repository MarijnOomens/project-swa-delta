#include "MainMenuScene.h"

MainMenuScene::MainMenuScene()
{
	this->name = "MainMenu";
	this->setBehaviourObjects({ std::make_shared<MainMenu>() });
	this->setTexture("mainmenu", "Assets/screen-components/mainmenu-designs/mainmenu-2.png");
	this->setTexture("button_play", "Assets/screen-components/button-designs/pastels/button-play-1.png");
	this->setTexture("button_credits", "Assets/screen-components/button-designs/pastels/button-credits-1.png");
	this->setTexture("button_exit", "Assets/screen-components/button-designs/pastels/button-exit-1.png");
	this->setTexture("ad", "Assets/ADS/Advertisement.png");
	
	this->setFont("joystix", "Assets/Font/joystix.ttf");
	this->setBeat("touch", "Assets/Audio/touch.ogg");
}