#pragma once
#include "main.h"
#include "TextureManager.h"
#include "BehaviourObject.h"
#include "AnimTypes.h"
#include "AnimFlip.h"
#include "AnimCategory.h"
#include <iostream>

class GraphicsComponent : public BehaviourObject {
public:
	Vector2D imageCoordinates;
	Vector2D imageDimensions = { 32, 32 };
	bool isScreen;

	ENGINE_API GraphicsComponent();
	ENGINE_API ~GraphicsComponent();

	ENGINE_API void playAnimation(int row, int frames, int speed, bool flip);

	ENGINE_API void setTexture(std::string name);
	ENGINE_API void update() override;
	ENGINE_API void addTextureManager(std::shared_ptr<TextureManager> tm);
	ENGINE_API void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos);
	ENGINE_API void connectCallback() override;
	ENGINE_API void callbackFunction() override;
	ENGINE_API std::shared_ptr<TextureManager>getTextureManager();
private:
	bool animated = false;
	int animFrames;
	int animSpeed;
	int animRow;
	bool flipped = false;

	std::map<std::string, AnimTypes> animTypes;

	std::shared_ptr<TextureManager> textureManager;
	std::string textureName;
};