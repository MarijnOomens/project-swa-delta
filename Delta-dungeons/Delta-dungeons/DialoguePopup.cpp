#include "DialoguePopup.h"

DialoguePopup::DialoguePopup()
{
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("dialogue_box");
	gc->isScreen = true;
	gc->imageDimensions = { 840, 292 };

	this->transform.position = { 100, 500 };
	gc->transform.position = this->transform.position;

	this->components.emplace_back(std::move(gc));

}

void DialoguePopup::playDialogue(std::vector<std::string> param)
{

}