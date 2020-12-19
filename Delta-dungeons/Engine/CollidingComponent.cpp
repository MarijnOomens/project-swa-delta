#include "CollidingComponent.h"

CollidingComponent::CollidingComponent(std::shared_ptr<CollisionStrategy> strategy)
{
	setStrategy(strategy);
}

CollidingComponent::CollidingComponent() {}

CollidingComponent::~CollidingComponent() {}

void CollidingComponent::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void CollidingComponent::interact(std::shared_ptr<BehaviourObject> interactor) {}

void CollidingComponent::update() {}

void CollidingComponent::start() {}

void CollidingComponent::setParent() {}

void CollidingComponent::actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction)
{
	strategy->actCollision(collider, x, y, direction);
}

void CollidingComponent::setStrategy(std::shared_ptr<CollisionStrategy> chosenStrategy) {
	strategy = chosenStrategy;
}
