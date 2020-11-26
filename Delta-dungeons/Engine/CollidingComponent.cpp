#include "CollidingComponent.h"

CollidingComponent::CollidingComponent()
{
	//setStrategy(std::make_shared<StopStrategy>());
}

CollidingComponent::~CollidingComponent() {}

void CollidingComponent::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void CollidingComponent::interact() {}

void CollidingComponent::update() {}

void CollidingComponent::actCollision(/*std::shared_ptr<CollidingComponent> collider,*/ int x, int y, KeyCodes direction)
{
	strategy->actCollision(/*collider,*/ x, y, direction);
}

void CollidingComponent::setStrategy(std::shared_ptr<CollisionStrategy> chosenStrategy) {
	strategy = chosenStrategy;
}
