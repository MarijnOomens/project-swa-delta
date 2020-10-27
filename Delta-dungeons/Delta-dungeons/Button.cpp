#include "Button.h"

Button::Button(int x, int y, TextureList textureList, GraphicsComponent* gc)
{
	m_gc = gc;
	components.push_back(m_gc);
	transform.position.x = x;
	transform.position.y = y;

	gc->transform = this->transform;

	possibleTextures = textureList;
	m_gc->setTexture(possibleTextures[0]);
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