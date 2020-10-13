#pragma once
#include "Transform.h";

class BehaviourObject {
	virtual void Update() = 0;
	virtual void callbackFunction() = 0;
	virtual void connectCallback() = 0;
public:
	Transform transform;
	BehaviourObject();
	~BehaviourObject();
};