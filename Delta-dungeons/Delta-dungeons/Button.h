#pragma once

#include "GameObject.h"
#include "GraphicsComponent.h"
#include <string>
#include <memory>

using TextureList = std::vector<std::string>;

class Button : public GameObject
{
public:
	Button(int x, int y, TextureList textureList, GraphicsComponent* gc);
	~Button();
	void update() override;
	void connectCallback() override;
	void callbackFunction() override;
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) override;
private:
	std::string text;
	TextureList possibleTextures;
	GraphicsComponent* m_gc;
};