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

void Collision::checkCollision(std::shared_ptr<CollidingComponent> collider, int x, int y, KeyCodes direction)
{
	
	for (auto collider2 : colliderObjects)
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
			if (KeyCodes::KEY_RIGHT == direction
				&& x == col2->transform.position.x
				&& y == col2->transform.position.y)
			{
				col2->actCollision(collider, x, y, direction);
				break;
			}
			/*facing up*/
			else if
				(KeyCodes::KEY_UP == direction
					&& y == col2->transform.position.y
					&& x == col2->transform.position.x)
			{
				col2->actCollision(collider, x, y, direction);
				break;
			}
			else if
				/*facing down*/
				(KeyCodes::KEY_DOWN == direction
					&& y == col2->transform.position.y
					&& x == col2->transform.position.x)
			{
				col2->actCollision(collider, x, y, direction);
				break;
			}
			else if
				/*facing left*/
				(KeyCodes::KEY_LEFT == direction 
					&& x == col2->transform.position.x
					&& y == col2->transform.position.y)
			{
				col2->actCollision(collider, x, y, direction);
				break;
			}
					
		}
	}
	//reset after actCollision
}