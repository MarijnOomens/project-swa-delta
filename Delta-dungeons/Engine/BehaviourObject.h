#pragma once
#include "main.h"
#include "Transform.h"
#include "Keycodes.h"
#include "KeyboardEvent.h"

class BehaviourObject {
	ENGINE_API virtual void callbackFunction() = 0;
	ENGINE_API virtual void connectCallback() = 0;
	
public:
	ENGINE_API virtual void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) = 0;
	ENGINE_API virtual void update() = 0;
	Transform transform;
	ENGINE_API BehaviourObject();
	ENGINE_API ~BehaviourObject();

};
