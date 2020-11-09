#pragma once

#include "GameObject.h"
#include "GraphicsComponent.h"
#include <string>
#include <memory>

class Button : public GameObject
{
public:
	Button();
	Button(int x, int y, std::vector<std::string> textureList);
	~Button();
	void update() override;
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) override;
private:
	std::string text;
	std::vector<std::string> possibleTextures;
	std::shared_ptr<GraphicsComponent> m_gc;
};