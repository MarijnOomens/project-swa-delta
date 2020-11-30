#include "Collision.h"

Collision::Collision() {}

void Collision::registerColliders(std::vector<std::shared_ptr<BehaviourObject>> colliders)
{
	colliderObjects = colliders;
}

void Collision::deleteColliderFromScene(std::shared_ptr<BehaviourObject> deletedCollider)
{
	auto index = std::find(colliderObjects.begin(), colliderObjects.end(), deletedCollider);
	if (index != colliderObjects.end())
	{
		colliderObjects.erase(index);
	}
}

void Collision::setCameraDimensions(Transform &transform) {
	cameraX = transform.position.x;
	cameraY = transform.position.y;
	cameraW = transform.scale.x;
	cameraH = transform.scale.y;
}

void Collision::checkCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w)
{
	for (auto& collider2 : colliderObjects)
	{
		if (
			collider != collider2 &&
			collider2->transform.position.x + 128 >= cameraX &&
			1280 + cameraX >= collider2->transform.position.x &&
			collider2->transform.position.y + 128 >= cameraY &&
			cameraY + 1024 >= collider2->transform.position.y
			)
		{
			auto col2 = dynamic_cast<CollidingComponent*>(collider2.get());
			/*facing right*/
			if (x + w > col2->transform.position.x &&
				col2->transform.position.x + w > x &&
				y + w > col2->transform.position.y &&
				col2->transform.position.y + w > y)
			{
				col2->actCollision(collider, x, y, direction);
				break;
			}
		}
	}
}
