#pragma once

#include "GameObject.h"
#include <map>

class InteractiveObject : public GameObject
{
public:
	std::map<std::string, std::string> textures;

	void handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) override;
	void update() override;
	void interact() override;
private:
	std::string name;
	std::string dialogue;
};