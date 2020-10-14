#include "Button.h"

Button::Button(int x, int y, TextureList textureList) {
	components.push_back(std::make_unique<BehaviourObject>(gc));
	transform.position.x = (float)x;
	transform.position.y = (float)y;

	possibleTextures = textureList;
};
Button::~Button() {};

void Button::Update() {

}

void Button::connectCallback() {};
void Button::callbackFunction() {};