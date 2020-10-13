#pragma once
#include <iostream>
#include "TextureManager.h"

class GraphicsComponent {
private:
	bool animated;
	int frames;
	int animationSpeed;
	int animationIndex;
	std::unique_ptr<TextureManager> textureManager;
	std::string textureName;

public:
	GraphicsComponent();
	~GraphicsComponent();
	void PlayAnimation(std::string path);
	void SetTexture(std::string tex, std::string name);
	void CallBackFunction();
	void draw();
};