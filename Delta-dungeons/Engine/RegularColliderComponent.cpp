#include "RegularColliderComponent.h"

RegularColliderComponent::RegularColliderComponent() 
{
	collisionFunc = nullptr;
	pointer = nullptr;
}

RegularColliderComponent::RegularColliderComponent(const cbCollision f, void* p) 
{
	collisionFunc = f;
	pointer = p;
}

void RegularColliderComponent::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void RegularColliderComponent::interact() {}

void RegularColliderComponent::update() {}

void RegularColliderComponent::actCollision(std::shared_ptr<BehaviourObject> right, std::shared_ptr<BehaviourObject> left, std::shared_ptr<BehaviourObject> up, std::shared_ptr<BehaviourObject> down)
{
	if (collisionFunc != nullptr)
	{
		collisionFunc(pointer, right, left, up, down);
	}
}