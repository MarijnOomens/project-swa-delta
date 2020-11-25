#include "DamageColliderComponent.h"

DamageColliderComponent::DamageColliderComponent() 
{
	collisionFunc = nullptr;
	pointer = nullptr;
}

DamageColliderComponent::DamageColliderComponent(const cbCollision f, void* p)
{
	collisionFunc = f;
	pointer = p;
}

void DamageColliderComponent::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void DamageColliderComponent::interact() {}

void DamageColliderComponent::update() {}

void DamageColliderComponent::actCollision(std::shared_ptr<BehaviourObject> right, std::shared_ptr<BehaviourObject> left, std::shared_ptr<BehaviourObject> up, std::shared_ptr<BehaviourObject> down)
{
	if (collisionFunc != nullptr)
	{
		collisionFunc(pointer, right, left, up, down);
	}
}