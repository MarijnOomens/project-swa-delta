#include "GameOverScreenScene.h"

GameOverScreenScene::GameOverScreenScene()
{
	this->name = "GameOverScreen";
	this->setBehaviourObjects({ std::make_shared<GameOverScreen>() });
	this->setTexture("game_over", "Assets/Menu/Game-Over/background.png");
	this->setTexture("button_next", "Assets/Menu/Button/button-next.png");
	this->setTexture("button_next_hover", "Assets/Menu/Button/button-next-hover.png");
}