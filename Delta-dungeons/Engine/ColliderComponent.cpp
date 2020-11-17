#include "ColliderComponent.h"

ColliderComponent::ColliderComponent() {
	collisionFunc = nullptr;
	pointer = nullptr;
}

ColliderComponent::ColliderComponent(const cbCollision f, void* p) : collisionFunc(f), pointer(p) {}

void ColliderComponent::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void ColliderComponent::interact() {}

void ColliderComponent::update() {}

void ColliderComponent::actCollision(int right, int left, int up, int down, std::string rightTag, std::string leftTag, std::string upTag, std::string downTag)
{
	if (collisionFunc != nullptr)
	{
		collisionFunc(pointer, right, left, up, down, rightTag, leftTag, upTag, downTag);
	}
}