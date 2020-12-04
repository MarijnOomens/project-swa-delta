#pragma once

#include "Screen.h"
#include "SceneModifier.h"

#include <string>
#include <vector>

class DialoguePopup : public Screen
{
public:
	DialoguePopup();

	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos);

	void playDialogue(std::vector<std::string> param);

};