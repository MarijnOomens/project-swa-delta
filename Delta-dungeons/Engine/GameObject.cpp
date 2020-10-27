#include "GameObject.h"

GameObject::GameObject() {}
GameObject::~GameObject() {}

void GameObject::addComponent(BehaviourObject* comp)
{
	components.push_back(comp);
}

void GameObject::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) {}

void GameObject::connectCallback() {}

void GameObject::update() {}