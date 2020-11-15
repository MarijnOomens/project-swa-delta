#include "Collision.h"

//collision 
Collision::Collision()
{
	colliderObjects = std::vector<std::shared_ptr<ColliderComponent>>();
}

void Collision::registerColliders(const std::vector<std::shared_ptr<ColliderComponent>> colliders)
{
	colliderObjects = colliders;
}

void Collision::registerCollider(const std::shared_ptr<ColliderComponent> collider)
{
	colliderObjects.emplace_back(collider);
}



//player roept het aan
void Collision::checkCollision()
{
	for (auto collider1 : colliderObjects) {
		//if true
		for (auto collider2: colliderObjects) {
			//if (collider1 != collider2) {
				if (collider1.get()->tag == "player") {
					//if (collider1.get()->x == collider2.get()->x && collider1.get()->y == collider2.get()->y)
					//{
						std::cout << "x: " << collider1.get()->x << " vs " << collider2.get()->x << " y: " << collider1.get()->y << " vs " << collider2.get()->y << std::endl;

						//collider1.get()->actCollision(collider2);
						std::cout << "it matched!" << std::endl;
						break;
						//collider1.get()->update(collider2);
						//collider2.get()->update(collider1);
					//}
				}

			//}

		}
		//compare xy with each other
			//collider.hasCollision
		//for()
	}
}

//check with each other.