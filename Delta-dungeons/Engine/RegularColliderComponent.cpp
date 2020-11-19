#include "RegularColliderComponent.h"

RegularColliderComponent::RegularColliderComponent() {
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

void RegularColliderComponent::actCollision(int right, int left, int up, int down, std::string rightTag, std::string leftTag, std::string upTag, std::string downTag)
{
	if (collisionFunc != nullptr)
	{
		collisionFunc(pointer, right, left, up, down, rightTag, leftTag, upTag, downTag, false);
	}
}