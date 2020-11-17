#include "ColliderComponent.h"

ColliderComponent::ColliderComponent() {
	collisionFunc = nullptr;
	pointer = nullptr;
}


ColliderComponent::ColliderComponent(const cbCollision f, void* p) : collisionFunc(f), pointer(p) {}

//constructor give player.cpp callback
void ColliderComponent::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void ColliderComponent::interact() {}

void ColliderComponent::update() {}

void ColliderComponent::actCollision(int right, int left, int up, int down)
{
	//std::cout << "it matches" << std::endl;
	if (collisionFunc != nullptr) 
	{
		collisionFunc(pointer, right, left, up, down);
	}
}