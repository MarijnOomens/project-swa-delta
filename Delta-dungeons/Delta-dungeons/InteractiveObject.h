#pragma once
#include "GameObject.h"
#include <map>

class InteractiveObject : public GameObject
{
public:
	virtual void interact() = 0;
	std::string name;
	std::string dialogue;
	std::map<std::string, std::string> textures;
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) override;
	void update() override;
};