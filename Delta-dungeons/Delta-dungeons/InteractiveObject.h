#pragma once

#include "GameObject.h"
#include <map>

class InteractiveObject : public GameObject
{
public:
	std::map<std::string, std::string> textures;

	virtual void interact() = 0;

	void handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) override;
	void update() override;

private:
	std::string name;
	std::string dialogue;
};