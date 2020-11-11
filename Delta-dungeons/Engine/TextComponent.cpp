#include "TextComponent.h"

/// <summary>
/// TextComponent holds all information of a text item that can be drawn onto the screen.
/// </summary>
/// <param name="text">The text shown on the screen.</param>
/// <param name="font">The font of the text.</param>
/// <param name="colour">The colour of the text.</param>
/// <param name="fontSize">The size of the text.</param>
TextComponent::TextComponent(std::string text, std::string font, Colour colour, int fontSize) : text(text), font(font), colour(colour), fontSize(fontSize) {}

/// <summary>
/// The update methods calls the TextureManager to draw the item.
/// </summary>
void TextComponent::update() {
	if (text != "")
	{
		textureManager->drawText(text, font, colour, this->transform, fontSize);
	}
}

void TextComponent::changeText(const std::string& text) {
	this->text = text;
}

/// <summary>
/// This methods adds a reference to the gobal TextureManager.
/// </summary>
/// <param name="tm">The TextureManager.</param>
void TextComponent::addTextureManager(std::shared_ptr<TextureManager> tm)
{
	textureManager = tm;
}

void TextComponent::connectCallback() {}

void TextComponent::callbackFunction() {}