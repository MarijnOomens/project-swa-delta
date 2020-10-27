#pragma once
#include <string>
#include <vector>
#include "GraphicsComponent.h"

class Screen : public GameObject
{
public:
	virtual void closeScreen() = 0;
	std::string text;
	std::shared_ptr<GraphicsComponent> gc;
	std::map<std::string, std::string> textures;

	void connectCallback() override;
	void callbackFunction() override;
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) override;
	void update() override;
};