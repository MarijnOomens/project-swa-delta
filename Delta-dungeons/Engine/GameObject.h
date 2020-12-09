#pragma once

#include "BehaviourObject.h"
#include <vector>
#include "main.h"

class GameObject : public BehaviourObject {
public:
	std::vector<std::shared_ptr<BehaviourObject>> components;

	ENGINE_API GameObject() {}

	ENGINE_API std::vector<std::shared_ptr<BehaviourObject>> getComponentsRecursive();
};