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

	bool checkedUp = false;
	bool checkedLeft = false;
	bool checkedRight = false;
	bool checkedDown = false;
	void registerColliders(std::vector<std::shared_ptr<BehaviourObject>> colliders);
	void deleteColliderFromScene(std::shared_ptr<BehaviourObject> deletedCollider);
	void checkCollision();
private:
	std::vector<std::shared_ptr<BehaviourObject>> colliderObjects;
};