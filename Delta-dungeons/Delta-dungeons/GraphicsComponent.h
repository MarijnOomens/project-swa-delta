#pragma once
#include <iostream>
#include "TextureManager.h"

class GraphicsComponent {
private:
	bool animated;
	int frames;
	int animationSpeed;
	int animationIndex;
	TextureManager* textureManager;

public:
	GraphicsComponent();
	~GraphicsComponent();
	void PlayAnimation(std::string path);
	void SetTexture(std::string tex);
	void CallBackFunction();
};