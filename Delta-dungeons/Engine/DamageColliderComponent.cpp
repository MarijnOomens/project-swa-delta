#include "DamageColliderComponent.h"

DamageColliderComponent::DamageColliderComponent() {
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

void DamageColliderComponent::actCollision(int right, int left, int up, int down, std::string rightTag, std::string leftTag, std::string upTag, std::string downTag)
{
	if (collisionFunc != nullptr)
	{
		collisionFunc(pointer, right, left, up, down, rightTag, leftTag, upTag, downTag, true);
	}
}