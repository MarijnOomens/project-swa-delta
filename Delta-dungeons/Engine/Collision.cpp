#include "Collision.h"

Collision::Collision()
{
}

void Collision::registerColliders(const std::vector<std::shared_ptr<ColliderComponent>> colliders)
{
	colliderObjects = colliders;
}

void Collision::deleteColliderFromScene(std::shared_ptr<ColliderComponent> deletedCollider)
{
	auto index = std::find(colliderObjects.begin(), colliderObjects.end(), deletedCollider);
	if (index != colliderObjects.end())
	{
		colliderObjects.erase(index);
	}
}

void Collision::checkCollision()
{
	for (auto collider1 : colliderObjects)
	{
		for (auto collider2 : colliderObjects)
		{
			if (collider1 != collider2)
			{
				//if (collider1->isTrigger)
				//{
				//	if (collider1->transform.position.x == collider2->transform.position.x && collider1->transform.position.y == collider2->transform.position.y)
				//	{
				//		std::cout << "x: " << collider1->transform.position.x << " vs " << collider2->transform.position.x << " y: " << collider1->transform.position.y << " vs " << collider2->transform.position.y << std::endl;
				//		std::cout << "it matched!" << std::endl;
				//		break;
				//	}
				//}
				//else //is collider tile
				//{
					/*facing right*/
				if ((collider1->transform.position.x + 128 == collider2->transform.position.x
					&& collider1->transform.position.y == collider2->transform.position.y))
				{
					rightX = collider2->transform.position.x;
				}
				
					/*facing up*/
				if
					(collider1->transform.position.y == collider2->transform.position.y + 128
						&& collider1->transform.position.x == collider2->transform.position.x)
				{
					upY = collider2->transform.position.y;
				}
				if
					/*facing down*/
					(collider1->transform.position.y + 128 == collider2->transform.position.y
						&& collider1->transform.position.x == collider2->transform.position.x)
				{
					downY = collider2->transform.position.y;
				}
				if
					/*facing left*/
					(collider1->transform.position.x == collider2->transform.position.x + 128
						&& collider1->transform.position.y == collider2->transform.position.y)
				{
					leftX = collider2->transform.position.x;
				}
					collider1->actCollision(collider2->tag, upY, leftX, rightX, downY);
					//std::cout << "x: " << collider1->transform.position.x << " vs " << collider2->transform.position.x << " y: " << collider1->transform.position.y << " vs " << collider2->transform.position.y << std::endl;
					//std::cout << "it matched!" << std::endl;
				//}
			}
		}
	}
	upY = -1;
	leftX = -1;
	rightX = -1;
	downY = -1;
}