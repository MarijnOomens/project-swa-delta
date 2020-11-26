#include "CollidingComponent.h"

CollidingComponent::CollidingComponent(std::shared_ptr<CollisionStrategy> strategy)
{
	setStrategy(strategy);
}

CollidingComponent::CollidingComponent() {}

CollidingComponent::~CollidingComponent() {}

void CollidingComponent::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void CollidingComponent::interact() {}

void CollidingComponent::update() {}

void CollidingComponent::actCollision(int x, int y, KeyCodes direction)
{
	strategy->actCollision(x, y, direction);
}

void CollidingComponent::setStrategy(std::shared_ptr<CollisionStrategy> chosenStrategy) {
	strategy = chosenStrategy;
}
