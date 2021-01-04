#include "HelpScreenScene.h"

HelpScreenScene::HelpScreenScene()
{
	this->name = "HelpScreen";
	this->setBehaviourObjects({ std::make_shared<HelpScreen>() });
	this->setTexture("help", "Assets/Menu/Help/background.png");
	this->setTexture("npc_icon", "Assets/Menu/Help/bugtrainer.png");
	this->setTexture("running_shoes_icon", "Assets/Menu/Help/running_shoes.png");
	this->setTexture("pokeball_icon", "Assets/Menu/Help/pokeball.png");
	this->setTexture("berry_icon", "Assets/Menu/Help/berry.png");
}