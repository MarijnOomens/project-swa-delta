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

void Collision::checkCollision()
{
	for (auto collider1 : colliderObjects)
	{
		auto col1 = dynamic_cast<ColliderComponent*>(collider1.get());
		for (auto collider2 : colliderObjects)
		{
			if (collider1 != collider2)
			{
				auto col2 = dynamic_cast<ColliderComponent*>(collider2.get());
				if (col1->isTrigger)
				{
					if (col1->transform.position.x == col2->transform.position.x && col1->transform.position.y == col2->transform.position.y)
					{
						std::cout << "x: " << col1->transform.position.x << " vs " << col2->transform.position.x << " y: " << col1->transform.position.y << " vs " << col2->transform.position.y << std::endl;
						std::cout << "it matched!" << std::endl;
						break;
					}
				}
				else
				{
					/*facing right*/
					if ((col1->transform.position.x + 128 == col2->transform.position.x
						&& col1->transform.position.y == col2->transform.position.y)
						||
						/*facing up*/
						(col1->transform.position.y == col2->transform.position.y + 128
							&& col1->transform.position.x == col2->transform.position.x)
						||
						/*facing down*/
						(col1->transform.position.y + 128 == col2->transform.position.y
							&& col1->transform.position.x == col2->transform.position.x)
						||
						/*facing left*/
						(col1->transform.position.x == col2->transform.position.x + 128
							&& col1->transform.position.y == col2->transform.position.y))
					{
						col1->actCollision(col2->transform.position.x, col2->transform.position.y, col2->tag);
						//std::cout << "x: " << collider1->transform.position.x << " vs " << collider2->transform.position.x << " y: " << collider1->transform.position.y << " vs " << collider2->transform.position.y << std::endl;
						//std::cout << "it matched!" << std::endl;
					}
				}
			}
		}
	}
}