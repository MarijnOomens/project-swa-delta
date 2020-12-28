#pragma once

#include "Screen.h"
#include "SceneModifier.h"
#include "DebugUtilities.h"
#include "GameState.h"

#include <string>
#include <vector>

class DialoguePopup : public Screen
{
public:
	DialoguePopup(const std::string& dialogue = "");

	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos);

};