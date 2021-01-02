#include "GameWinScreenScene.h"

GameWinScreenScene::GameWinScreenScene()
{
	this->name = "GameWinScreen";
	this->setBehaviourObjects({ std::make_shared<GameWinScreen>() });
	this->setTexture("game_win", "Assets/Menu/Game-Win/background.png");
	this->setTexture("button_next", "Assets/Menu/Button/button-next.png");
	this->setTexture("button_next_hover", "Assets/Menu/Button/button-next-hover.png");
	this->setBeat("credits", "Assets/Audio/credits.ogg");
}