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
	void connectCallback() override;
	void callbackFunction() override;
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) override;
	void update() override;
	void updatePositions(int x, int y)override = 0;
};