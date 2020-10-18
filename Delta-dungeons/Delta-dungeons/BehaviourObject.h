#pragma once
#include "Transform.h"

class BehaviourObject {
	virtual void callbackFunction() = 0;
	virtual void connectCallback() = 0;
public:
	virtual void Update() = 0;
	Transform transform;
	BehaviourObject();
	~BehaviourObject();
};