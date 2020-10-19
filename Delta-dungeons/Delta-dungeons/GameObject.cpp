#include "GameObject.h"

GameObject::GameObject() {};
GameObject::~GameObject() {};

void GameObject::ConnectCallback() {}
void GameObject::Update()
{

};

void GameObject::addComponent(BehaviourObject* comp) {
	components.push_back(comp);
}