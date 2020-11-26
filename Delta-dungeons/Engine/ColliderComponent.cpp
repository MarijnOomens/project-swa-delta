#include "ColliderComponent.h"


ColliderComponent::ColliderComponent()
{
	collisionFunc = nullptr;
	pointer = nullptr;
}

ColliderComponent::ColliderComponent(const cbCollision f, void* p)
{
	setStrategy(std::make_shared<StopStrategy>());
	collisionFunc = f;
	pointer = p;
}

void ColliderComponent::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void ColliderComponent::interact() {}

void ColliderComponent::update() {}

void ColliderComponent::actCollision(std::shared_ptr<ColliderComponent> collider, int x, int y, KeyCodes direction)
{
	
	strategy->actCollision(collider, x, y, direction);
	//if (collisionFunc != nullptr)
	//{
	//	collisionFunc(pointer, collider, x, y, direction);
	//}
}

void ColliderComponent::setStrategy(std::shared_ptr<Strategy> chosenStrategy) {
	strategy = chosenStrategy;
}

