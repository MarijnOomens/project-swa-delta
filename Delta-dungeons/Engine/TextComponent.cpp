#include "TextComponent.h"

TextComponent::TextComponent(std::string text, std::string font, Colour colour, int fontSize) : text(text), font(font), colour(colour), fontSize(fontSize) {

}

TextComponent::~TextComponent() {}

void TextComponent::update() {
	textureManager->drawText(text, font, colour, this->transform, fontSize);
}

void TextComponent::addTextureManager(std::shared_ptr<TextureManager> tm)
{
	textureManager = tm;
}

void TextComponent::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) {}

void TextComponent::connectCallback() {}

void TextComponent::callbackFunction() {}