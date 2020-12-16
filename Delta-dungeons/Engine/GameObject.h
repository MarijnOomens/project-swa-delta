#pragma once

#include "BehaviourObject.h"
#include <vector>
#include "main.h"

class GameObject : public BehaviourObject {
public:
	std::vector<std::shared_ptr<BehaviourObject>> components;

	ENGINE_API GameObject() {}

	ENGINE_API virtual void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) = 0;

	ENGINE_API std::vector<std::shared_ptr<BehaviourObject>> getComponentsRecursive();
};