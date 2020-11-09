#pragma once
#include "BehaviourObject.h"
#include "Colour.h"
#include "TextureManager.h"
#include "main.h"

class TextComponent : public BehaviourObject {
public:
	ENGINE_API TextComponent(std::string text, std::string font, Colour colour, int fontSize);
	ENGINE_API ~TextComponent();

	ENGINE_API void addTextureManager(std::shared_ptr<TextureManager> tm);

	void update() override;
	void connectCallback() override;
	void callbackFunction() override;
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos) override;

private:
	std::shared_ptr<TextureManager> textureManager;
	std::string text;
	std::string font;
	Colour colour;
	int fontSize = 16;
};