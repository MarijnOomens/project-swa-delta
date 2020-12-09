#pragma once
#include <vector>
#include "CollidingComponent.h"
#include "IInteractiveObject.h"

class Collision {
public:
	Collision();
	~Collision() {}

	int cameraX = 0;
	int cameraY = 0;
	int cameraW = 0;
	int cameraH = 0;

	void setCameraDimensions(const Transform& transform);
	void registerColliders(std::vector<std::shared_ptr<BehaviourObject>> colliders);
	void deleteColliderFromScene(std::shared_ptr<BehaviourObject> deletedCollider);
	void checkCollision(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w);
	void checkProjectileCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w);
private:
	std::vector<std::shared_ptr<BehaviourObject>> colliderObjects;
};