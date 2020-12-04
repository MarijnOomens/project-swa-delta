#pragma once

#include "Screen.h"
#include "SceneModifier.h"

#include <string>
#include <vector>

class DialoguePopup : public Screen
{
public:
	DialoguePopup();

	void playDialogue(std::vector<std::string> param);

};