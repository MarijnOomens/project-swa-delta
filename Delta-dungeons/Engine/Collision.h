#pragma once
#include <vector>
#include "ColliderComponent.h"
class Collision {
public:
	Collision();
	~Collision() {}
	void registerColliders(const std::vector<std::shared_ptr<ColliderComponent>> colliders);
	void deleteColliderFromScene(std::shared_ptr<ColliderComponent> deletedCollider);
	void checkCollision();
private:
	std::vector<std::shared_ptr<ColliderComponent>> colliderObjects;
};