#include "Button.h"

Button::Button() {};
Button::Button(int x, int y, std::vector<std::string> textureList) {
	m_gc = std::make_shared<GraphicsComponent>();
	transform.position = { x, y };

	m_gc->transform = this->transform;
	m_gc->imageDimensions = { 140, 50 };
	m_gc->transform.scale.Multiply({ 2, 2 });

	possibleTextures = textureList;
	m_gc->setTexture(possibleTextures[0]);
	this->components.emplace_back(m_gc);
};

Button::~Button() {}

void Button::update() {}

void Button::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent)
{
	std::cout << keyCode << std::endl;
	if (keyCode == KEY_UP) {
		this->transform.position.x + 1;
	}
	else if (keyCode == KEY_DOWN) {
		this->transform.position.x - 1;
	}
	for (auto& comp : components)
	{
		comp->transform = this->transform;
	}
};

void Button::connectCallback() {}

void Button::callbackFunction() {}