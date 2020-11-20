#pragma once

#include "main.h"
#include "Transform.h"
#include "Keycodes.h"
#include "KeyboardEvent.h"

class BehaviourObject {
public:
	Transform transform;

	ENGINE_API BehaviourObject();
	ENGINE_API virtual ~BehaviourObject() = default;
	ENGINE_API BehaviourObject(BehaviourObject const& other) = delete;
	ENGINE_API BehaviourObject(BehaviourObject &&other) = delete;
	ENGINE_API BehaviourObject &operator=(BehaviourObject const& other) = delete;
	ENGINE_API BehaviourObject &operator=(BehaviourObject &&other) = delete;

	ENGINE_API virtual void handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) = 0;
	ENGINE_API virtual void update() = 0;
	ENGINE_API virtual void interact() = 0;
};
