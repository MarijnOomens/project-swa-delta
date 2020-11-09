#pragma once

#include "main.h"
#include "Transform.h"
#include "Keycodes.h"
#include "KeyboardEvent.h"

class BehaviourObject {
public:
	ENGINE_API BehaviourObject();
	ENGINE_API ~BehaviourObject();

	ENGINE_API virtual void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) = 0;
	ENGINE_API virtual void update() = 0;

	Transform transform;
};
