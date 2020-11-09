#pragma once

#include <string>
#include <vector>
#include "GraphicsComponent.h"

class Screen : public GameObject
{
public:
	virtual void closeScreen() = 0;
	std::shared_ptr<GraphicsComponent> gc;
	std::map<std::string, std::string> textures;
	std::map<std::string, std::string> fonts;

	void connectCallback() override;
	void callbackFunction() override;
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos) override;
	void update() override;
};