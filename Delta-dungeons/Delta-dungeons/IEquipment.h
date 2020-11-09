#pragma once
#include "GameObject.h"

class IEquipment : public GameObject
{
public:
	virtual void use() = 0;

	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) override;
	void update() override;
};