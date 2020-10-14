#pragma once
#include <string>
#include "GameObject.h";
#include <memory>;

using TextureList = std::vector<std::string>;

class Button : public GameObject
{

public:
	Button(int x, int y, TextureList textureList);
	~Button();
	void click();
	void Update() override;
	void connectCallback() override;
	void callbackFunction() override;

private:
	std::string text;
	TextureList possibleTextures;
	GraphicsComponent* gc;
};