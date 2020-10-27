#pragma once
#include "BehaviourObject.h"
#include <vector>
#include <memory>

class GameObject : public BehaviourObject {
public:
	GameObject();
	~GameObject();

	virtual void ConnectCallback(); //Add callbackfunction
	virtual void Update();
	virtual void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent);
	std::vector<std::shared_ptr<BehaviourObject>> components;
};