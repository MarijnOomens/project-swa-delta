#include "ColliderComponent.h"

ColliderComponent::ColliderComponent(const cbCollision f, void* p) : collisionFunc(f), pointer(p) {}
//constructor give player.cpp callback
void ColliderComponent::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void ColliderComponent::interact() {}

void ColliderComponent::update() {
	
}


void ColliderComponent::actCollision(std::shared_ptr<ColliderComponent> collider2)
{
	if (transform.position.x == collider2.get()->transform.position.x && transform.position.y == collider2.get()->transform.position.y) {
		std::cout << "it matches" << std::endl;
	}
	//collisionFunc(pointer);
}