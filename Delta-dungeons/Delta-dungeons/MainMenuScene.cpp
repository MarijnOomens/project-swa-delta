#include "MainMenuScene.h"

MainMenuScene::MainMenuScene()
{
	this->name = "MainMenu";
	this->setBehaviourObjects({ std::make_shared<MainMenu>() });
}
