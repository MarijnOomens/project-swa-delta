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
		//if (recA.x + recA.w >= recB.x &&
		//	recB.x + recB.w >= recA.x &&
		//	recA.y + recA.h >= recB.y &&
		//	recB.y + recB.h >= recA.y)
		if (

			collider1->transform.position.x + 128 >= cameraX && 
			cameraW + cameraX >= collider1->transform.position.x && 
			collider1->transform.position.y + 128 >= cameraY &&
			cameraY + cameraH >= collider1->transform.position.y

			//collider1->transform.position.y + 128 < cameraY
			//&& !collider1->transform.position.x > cameraW && !collider1->transform.position.y + 128 < cameraY
			//&& !collider1->transform.position.x + 128 < cameraX && !collider1->transform.position.y > cameraH
			//&& !collider1->transform.position.x > cameraW && !collider1->transform.position.y > cameraH
			) 
		{
			auto col1 = dynamic_cast<ColliderComponent*>(collider1.get());
			for (auto collider2 : colliderObjects)
			{
				if (
					collider1 != collider2 &&
					collider2->transform.position.x + 128 >= cameraX &&
					cameraW + cameraX >= collider2->transform.position.x &&
					collider2->transform.position.y + 128 >= cameraY &&
					cameraY + cameraH >= collider2->transform.position.y
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
							rightX = col2->transform.position.x;
							rightTag = col2->tag;
						}
						/*facing up*/
						else if
							(!checkedUp
								&& col1->transform.position.y == col2->transform.position.y + 128
								&& col1->transform.position.x == col2->transform.position.x)
						{
							checkedUp = true;
							upY = col2->transform.position.y;
							upTag = col2->tag;
						}
						else if
							/*facing down*/
							(!checkedDown
								&& col1->transform.position.y + 128 == col2->transform.position.y
								&& col1->transform.position.x == col2->transform.position.x)
						{
							checkedDown = true;
							downY = col2->transform.position.y;
							downTag = col2->tag;
						}
						else if
							/*facing left*/
							(!checkedLeft
								&& col1->transform.position.x == col2->transform.position.x + 128
								&& col1->transform.position.y == col2->transform.position.y)
						{
							checkedLeft = true;
							leftX = col2->transform.position.x;
							leftTag = col2->tag;
						}
					}
				}
			}
			col1->actCollision(rightX, leftX, upY, downY, rightTag, leftTag, upTag, downTag);
			//reset after actCollision
			checkedRight = checkedLeft = checkedUp = checkedDown = false;
			rightX = leftX = upY = downY = -1;
			rightTag = leftTag = upTag = downTag = "";
		}
	}
}