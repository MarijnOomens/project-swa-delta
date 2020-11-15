#include "ColliderComponent.h"

ColliderComponent::ColliderComponent(const cbCollision f, void* p) : collisionFunc(f), pointer(p) {}

//constructor give player.cpp callback
void ColliderComponent::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void ColliderComponent::interact() {}

void ColliderComponent::update() {}

void ColliderComponent::actCollision(std::string tag)
{
	//std::cout << "it matches" << std::endl;

	collisionFunc(pointer, tag);
}