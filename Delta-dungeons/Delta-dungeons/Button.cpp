#include "Button.h"

Button::Button(int x, int y, TextureList textureList, GraphicsComponent* gc) {
	m_gc = gc;
	components.push_back(m_gc);
	transform.position.x = (float)x;
	transform.position.y = (float)y;

	possibleTextures = textureList;
	m_gc->SetTexture();
};
Button::~Button() {};

void Button::Update() {

}

void Button::connectCallback() {};
void Button::callbackFunction() {};