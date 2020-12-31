#include "CreditScreenScene.h"

CreditScreenScene::CreditScreenScene()
{
	this->name = "CreditScreen";
	this->setBehaviourObjects({ std::make_shared<CreditScreen>() });
	this->setTexture("credits", "Assets/Menu/Credits/background.png");
	this->setTexture("button_back", "Assets/Menu/Button/button-back.png");
	this->setBeat("mii", "Assets/Audio/mii.ogg");
}