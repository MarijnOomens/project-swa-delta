#include "UIText.h"

UIText::UIText(int xPos, int yPos, std::string text, std::string font, Colour& colour) : text(text), font(font), textColour(colour)
{
	this->transform.position = { xPos, yPos };
}

void UIText::setText(std::string text)
{

}