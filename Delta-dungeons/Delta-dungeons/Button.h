#pragma once
#include <string>
#include "GameObject.h"
#include <memory>
#include "GraphicsComponent.h"

using TextureList = std::vector<std::string>;

class Button : public GameObject
{

public:
	Button(int x, int y, TextureList textureList);
	~Button();
	void update() override;
	void connectCallback() override;
	void callbackFunction() override;
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) override;
private:
	std::string text;
	TextureList possibleTextures;
	std::shared_ptr<GraphicsComponent> m_gc;
};