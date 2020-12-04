#include "HelpScreenScene.h"

HelpScreenScene::HelpScreenScene()
{
	this->name = "HelpScreen";
	this->setBehaviourObjects({ std::make_shared<HelpScreen>() });
	this->setTexture("help", "Assets/Menu/Help/background.png");
}