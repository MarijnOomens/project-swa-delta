#include "Button.h"

Button::Button(int x, int y, TextureList textureList, GraphicsComponent* gc) {
	m_gc = gc;
	components.push_back(m_gc);
	transform.position.x = (float)x;
	transform.position.y = (float)y;

	possibleTextures = textureList;
	m_gc->SetTexture(possibleTextures[0]);
};
Button::~Button() {};

int count = 0;

void Button::Update() {
	std::cout << count << std::endl;
	count++;
	//std::cout << "Button updated!" << std::endl;
}

void Button::connectCallback() {};
void Button::callbackFunction() {};