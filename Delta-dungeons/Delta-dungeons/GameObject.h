#pragma once
#include "BehaviourObject.h"
#include <vector>

class GameObject : public BehaviourObject {
public:
	GameObject();
	~GameObject();

	virtual void ConnectCallback(); //Add callbackfunction
	virtual void Update();
	virtual void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent);
	std::vector<BehaviourObject*> components;
	void addComponent(BehaviourObject* comp);
};