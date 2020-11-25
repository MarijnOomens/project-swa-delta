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

void Collision::checkCollision()
{

	for (auto collider1 : colliderObjects)
	{
		if (

			collider1->transform.position.x + 128 >= cameraX && 
			1280 + cameraX >= collider1->transform.position.x && 
			collider1->transform.position.y + 128 >= cameraY &&
			cameraY + 1024 >= collider1->transform.position.y
			) 
		{
			auto col1 = dynamic_cast<ColliderComponent*>(collider1.get());
			for (auto collider2 : colliderObjects)
			{
				if (
					collider1 != collider2 &&
					collider2->transform.position.x + 128 >= cameraX &&
					1280 + cameraX >= collider2->transform.position.x &&
					collider2->transform.position.y + 128 >= cameraY &&
					cameraY + 1024 >= collider2->transform.position.y
					)
				{
					auto col2 = dynamic_cast<ColliderComponent*>(collider2.get());
					if (col1->isTrigger)
					{
						if (col1->transform.position.x == col2->transform.position.x && col1->transform.position.y == col2->transform.position.y)
						{
							break;
						}
					}
					else
					{
						/*facing right*/
						if ((!checkedRight
							&& col1->transform.position.x + 128 == col2->transform.position.x
							&& col1->transform.position.y == col2->transform.position.y))
						{
							checkedRight = true;
							rightX = collider2;
							rightTag = col2->tag;
						}
						/*facing up*/
						else if
							(!checkedUp
								&& col1->transform.position.y == col2->transform.position.y + 128
								&& col1->transform.position.x == col2->transform.position.x)
						{
							checkedUp = true;
							upY = collider2;
							upTag = col2->tag;
						}
						else if
							/*facing down*/
							(!checkedDown
								&& col1->transform.position.y + 128 == col2->transform.position.y
								&& col1->transform.position.x == col2->transform.position.x)
						{
							checkedDown = true;
							downY = collider2;
							downTag = col2->tag;
						}
						else if
							/*facing left*/
							(!checkedLeft
								&& col1->transform.position.x == col2->transform.position.x + 128
								&& col1->transform.position.y == col2->transform.position.y)
						{
							checkedLeft = true;
							leftX = collider2;
							leftTag = col2->tag;
						}
					}
				}
			}
			col1->actCollision(rightX, leftX, upY, downY);
			//reset after actCollision
			checkedRight = checkedLeft = checkedUp = checkedDown = false;
			rightX = leftX = upY = downY = nullptr;
			rightTag = leftTag = upTag = downTag = "";
		}
	}
}