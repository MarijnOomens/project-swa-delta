#pragma once
#include "BehaviourObject.h"
#include <vector>

class GameObject : public BehaviourObject {
public:
	GameObject();
	~GameObject();

	virtual void ConnectCallback(); //Add callbackfunction
	virtual void Update();
	std::vector<BehaviourObject*> components;
	void addComponent(BehaviourObject* comp);
};