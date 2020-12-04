#include "GameOverScreenScene.h"

GameOverScreenScene::GameOverScreenScene()
{
	this->name = "GameOverScreen";
	this->setBehaviourObjects({ std::make_shared<GameOverScreen>() });

}