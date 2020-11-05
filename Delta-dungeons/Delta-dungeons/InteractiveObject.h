#pragma once
#include "GameObject.h"

class InteractiveObject : public GameObject
{
public:
	virtual void interact() = 0;

	void connectCallback() override;
	void callbackFunction() override;
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) override;
	void update() override;
	void updatePositions(int x, int y)override = 0;
};