#include "LoadSaveScreenScene.h"

LoadSaveScreenScene::LoadSaveScreenScene()
{
	this->name = "LoadSaveScreen";
	this->setBehaviourObjects({ std::make_shared<LoadSaveScreen>() });
	this->setTexture("load_save", "Assets/Menu/Load-Save/background.png");
	this->setTexture("button_continue", "Assets/Menu/Button/button-continue.png");
	this->setTexture("button_new", "Assets/Menu/Button/button-new.png");
}