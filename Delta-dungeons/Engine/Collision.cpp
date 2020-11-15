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

//player roept het aan
//void Collision::checkCollision()
//{
//	for (auto collider : colliderObjects) {
//		//if true
//		//compare xy with each other
//			//collider.hasCollision
//		//for()
//		collider.get()->update();
//	}
//}

//check with each other.