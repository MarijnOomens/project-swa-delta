#include "DialoguePopupScene.h"

DialoguePopupScene::DialoguePopupScene()
{
	this->name = "Dialogue";
	this->setBehaviourObjects({ std::make_shared<DialoguePopup>() });
	this->setTexture("dialogue_box", "Assets/Dialogue/text_box.png");
}