#pragma once

#include "BehaviourObject.h"
#include <vector>
#include "main.h"

class GameObject : public BehaviourObject {
public:
	ENGINE_API GameObject();
	ENGINE_API ~GameObject();

	ENGINE_API virtual void ConnectCallback(); //Add callbackfunction
	ENGINE_API virtual void Update();
	ENGINE_API virtual void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent);
	std::vector<BehaviourObject*> components;
	ENGINE_API void addComponent(BehaviourObject* comp);
};