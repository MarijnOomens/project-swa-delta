#include "LoadSaveScreenScene.h"

LoadSaveScreenScene::LoadSaveScreenScene()
{
	this->name = "LoadSaveScreen";
	this->setBehaviourObjects({ std::make_shared<LoadSaveScreen>() });
	this->setTexture("load_save", "Assets/Menu/Load-Save/background.png");
	this->setTexture("button_load", "Assets/Menu/Button/button-load.png");
}