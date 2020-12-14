#include "HighScoreScreenScene.h"

HighScoreScreenScene::HighScoreScreenScene()
{
	this->name = "HighScoreScreen";
	setBehaviourObjects({ std::make_shared<HighScoreScreen>() });
	this->setTexture("high_score", "Assets/Menu/HighScore/background.png");
}