#pragma once
#include <vector>
#include "ColliderComponent.h"
class Collision {
public:
	Collision();
	~Collision() {}
	void registerColliders(const std::vector<std::shared_ptr<ColliderComponent>> colliders);
	void checkCollision();
	void registerCollider(const std::shared_ptr<ColliderComponent> collider);
private:
	std::vector<std::shared_ptr<ColliderComponent>> colliderObjects;
};