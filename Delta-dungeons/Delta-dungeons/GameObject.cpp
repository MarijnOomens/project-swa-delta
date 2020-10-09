#include "GameObject.h"

GameObject::GameObject() {};
GameObject::~GameObject() {};

void GameObject::ConnectCallback() {}
void GameObject::Update()
{

};

void GameObject::draw() {
	if (checkGraphicsComponent()) {
		graphicsComponent.draw();
	}
}

bool GameObject::checkGraphicsComponent() {
	return true;
}
