#include "Collision.h"

Collision::Collision()
{
	colliderObjects = std::vector<std::shared_ptr<ColliderComponent>>();
}

void Collision::registerColliders(const std::vector<std::shared_ptr<ColliderComponent>> colliders)
{
	colliderObjects = colliders;
}

//delete collisioncomponent collider2-> player if (collider2->tag = "tile"){tileCollision = true }

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
					if (collider1->transform.position.x == collider2->transform.position.x && collider1->transform.position.y == collider2->transform.position.y)
					{
						collider1->actCollision(collider2->tag);
						std::cout << "x: " << collider1->transform.position.x << " vs " << collider2->transform.position.x << " y: " << collider1->transform.position.y << " vs " << collider2->transform.position.y << std::endl;
						std::cout << "it matched!" << std::endl;
						break;
					}
				//}
			}
		}
	}
}