#pragma once
#include "GameObject.h"
#include "Colour.h"
#include "TextureManager.h"

class UIComponent : public BehaviourObject
{
public:
	std::shared_ptr<TextureManager> textureManager;
	UIComponent(std::string text, std::string font, Colour& colour, int fontSize);
	~UIComponent();

	void renderText();
	void setText(std::string text);
private:
	std::string text;
	std::string font;
	Colour textColour;
	int fontSize;
};