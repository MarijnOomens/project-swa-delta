#pragma once
#include "BehaviourObject.h"
#include "Colour.h"
#include "FontManager.h"
#include "main.h"

class TextComponent : public BehaviourObject {
public:
	ENGINE_API TextComponent(const std::string& text, const std::string& font, const Colour& colour, int fontSize);
	ENGINE_API ~TextComponent() {};

	ENGINE_API void changeText(const std::string& text);
	ENGINE_API void addFontManager(std::shared_ptr<FontManager> fm);

	void update() override;
	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void start() override;
	void setParent() override;

private:
	std::shared_ptr<FontManager> fontManager;
	std::string text;
	std::string font;
	Colour colour;
	int fontSize = 16;
};