#pragma once

#include <iostream>
#include "TextureManager.h"
#include "BehaviourObject.h"
#include "main.h"

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
	ENGINE_API GraphicsComponent();

	ENGINE_API ~GraphicsComponent();
	ENGINE_API void playAnimation(std::string path);
	ENGINE_API void setTexture(std::string name);
	ENGINE_API void callbackFunction() override;
	//void draw();
	ENGINE_API void update() override;
	ENGINE_API void connectCallback() override;
	ENGINE_API void addTextureManager(std::shared_ptr<TextureManager> tm);
	ENGINE_API void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent);
};