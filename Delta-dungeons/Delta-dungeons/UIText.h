#pragma once
#include "GameObject.h"
#include "Colour.h"

class UIText : public GameObject
{
public:

	UIText(int xPos, int yPos, std::string text, std::string font, Colour& colour);
	~UIText();

	void setText(std::string text);
private:
	std::string text;
	std::string font;
	Colour textColour;
};