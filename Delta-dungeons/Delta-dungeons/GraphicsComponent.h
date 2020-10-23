#pragma once
#include <iostream>
#include "TextureManager.h"
#include "BehaviourObject.h"

class GraphicsComponent : public BehaviourObject {
private:
	bool animated = false;
	int frames = 0;
	int animationSpeed = 100;
	std::shared_ptr<TextureManager> textureManager;
	std::string textureName;

public:
	int animationIndex = 0;
	Vector2D imageCoordinates;
	GraphicsComponent();
	~GraphicsComponent();
	void PlayAnimation(std::string path);
	void SetTexture(std::string name);
	void callbackFunction() override;
	//void draw();
	void Update() override;
	void connectCallback() override;
	void addTextureManager(std::shared_ptr<TextureManager> tm);
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent);
};