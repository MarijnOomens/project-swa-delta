#include "GameWinScreenScene.h"

GameWinScreenScene::GameWinScreenScene()
{
	this->name = "GameWinScreen";
	this->setBehaviourObjects({ std::make_shared<GameWinScreen>() });
	this->setTexture("game_win", "Assets/Menu/Game-Win/background.png");
}