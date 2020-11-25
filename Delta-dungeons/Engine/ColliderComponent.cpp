#include "ColliderComponent.h"

ColliderComponent::ColliderComponent() {}

void ColliderComponent::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void ColliderComponent::interact() {}

void ColliderComponent::update() {}
void ColliderComponent::actCollision(std::shared_ptr<BehaviourObject> right, std::shared_ptr<BehaviourObject> left, std::shared_ptr<BehaviourObject> up, std::shared_ptr<BehaviourObject> down){}
