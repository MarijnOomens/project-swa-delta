#pragma once
#include "main.h"
#include "TextureManager.h"
#include "BehaviourObject.h"
#include <iostream>

class GraphicsComponent : public BehaviourObject {
public:
	int animationIndex = 0;
	Vector2D imageCoordinates;
	Vector2D imageDimensions = { 32, 32 };

	ENGINE_API GraphicsComponent();
	ENGINE_API ~GraphicsComponent();

	ENGINE_API void playAnimation(std::string path);
	ENGINE_API void setTexture(std::string name);
	ENGINE_API void update() override;
	ENGINE_API void addTextureManager(std::shared_ptr<TextureManager> tm);
	ENGINE_API void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent);
	ENGINE_API void connectCallback() override;
	ENGINE_API void callbackFunction() override;
	ENGINE_API std::shared_ptr<TextureManager>getTextureManager();
private:
	bool animated = false;
	int frames = 0;
	int animationSpeed = 100;
	std::shared_ptr<TextureManager> textureManager;
	std::string textureName;
};