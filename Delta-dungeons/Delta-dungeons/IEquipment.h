#pragma once
#include "GameObject.h"
#include <map>

class IEquipment : public GameObject
{
public:
	virtual void use() = 0;

	std::string name;
	std::string collectMessage;
	std::map<std::string, std::string> textures;

	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos) override;
	void update() override;
};