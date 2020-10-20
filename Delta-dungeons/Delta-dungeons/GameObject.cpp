#include "GameObject.h"

GameObject::GameObject() {};
GameObject::~GameObject() {};

void GameObject::ConnectCallback() {}
void GameObject::Update() {};

void GameObject::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) {
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

void GameObject::addComponent(BehaviourObject* comp) {
	components.push_back(comp);
}