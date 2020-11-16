#pragma once
#include <vector>
#include "ColliderComponent.h"
class Collision {
public:
	Collision();
	~Collision() {}
	int upY = -1;
	int leftX = -1;
	int rightX = -1;
	int downY = -1;
	void registerColliders(const std::vector<std::shared_ptr<ColliderComponent>> colliders);
	void deleteColliderFromScene(std::shared_ptr<ColliderComponent> deletedCollider);
	void checkCollision();
private:
	std::vector<std::shared_ptr<ColliderComponent>> colliderObjects;
};