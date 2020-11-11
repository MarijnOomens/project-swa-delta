#pragma once

#include "BehaviourObject.h"

class HUDComponent : public BehaviourObject {
public:
	int layer;
	HUDComponent(int layerlevel);
};