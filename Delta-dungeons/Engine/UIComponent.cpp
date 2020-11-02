#include "UIComponent.h"

UIComponent::UIComponent(std::string text, std::string font, Colour& colour, int fontSize) : text(text), font(font), textColour(colour),
 fontSize(fontSize)
{

}

void UIComponent::renderText()
{

}

void UIComponent::setText(std::string text)
{
	this->text = text;
}