#include "UIText.h"
UIText::UIText() {};
UIText::UIText(int x, int y, std::string txt, Colour colur) {
	m_gc = std::make_shared<GraphicsComponent>();
	transform.position = { x, y };

	m_gc->transform = this->transform;
	m_gc->transform.scale.multiply({ 1, 1 });

	text = txt;
	font = "comic";
	color = colur;
	this->components.emplace_back(m_gc);
};

UIText::~UIText() {}

void UIText::update() {}

void UIText::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) {}

void UIText::connectCallback() {}

void UIText::callbackFunction() {}