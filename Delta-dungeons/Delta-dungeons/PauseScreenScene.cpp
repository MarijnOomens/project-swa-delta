#include "PauseScreenScene.h"

PauseScreenScene::PauseScreenScene()
{
	this->name = "PauseScreen";
	this->setBehaviourObjects({ std::make_shared<PauseScreen>() });
	this->setTexture("pause", "Assets/Menu/Pause/Pause_filter.png");
	this->setTexture("button_save", "Assets/Menu/Button/button-save.png");
	this->setBeat("save", "Assets/Audio/save.wav");
}