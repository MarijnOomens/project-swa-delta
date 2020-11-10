#pragma once

#include "BehaviourObject.h"
#include <vector>
#include "main.h"

class GameObject : public BehaviourObject {
public:
	std::vector<std::shared_ptr<BehaviourObject>> components;

	ENGINE_API GameObject();
	ENGINE_API ~GameObject();

	ENGINE_API virtual void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos);
	ENGINE_API virtual void connectCallback(); //Add callbackfunction
	ENGINE_API virtual void update();
	ENGINE_API std::vector<std::shared_ptr<BehaviourObject>> getComponentsRecursive();//ENGINE_API IF NEEDED FOR GAME
};