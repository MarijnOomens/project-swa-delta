#include "GameObject.h"

GameObject::GameObject() {};
GameObject::~GameObject() {};

void GameObject::ConnectCallback() {}
void GameObject::Update() {};

void GameObject::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) {};

void GameObject::addComponent(BehaviourObject* comp) {
	components.push_back(comp);
}