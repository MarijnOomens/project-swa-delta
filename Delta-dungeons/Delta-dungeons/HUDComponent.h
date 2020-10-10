#pragma once
#include "BehaviourObject.h"

class HUDComponent : public BehaviourObject {
public:
	HUDComponent(int layerlevel);
	int layer;
};