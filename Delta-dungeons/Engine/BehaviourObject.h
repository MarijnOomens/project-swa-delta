#pragma once

#include "main.h"
#include "Transform.h"
#include "Keycodes.h"
#include "KeyboardEvent.h"
#include <iostream>

class BehaviourObject : public std::enable_shared_from_this<BehaviourObject> {
public:
	Transform transform;

	ENGINE_API BehaviourObject();
	ENGINE_API virtual ~BehaviourObject()= default;
	ENGINE_API BehaviourObject(BehaviourObject const& other) = delete;
	ENGINE_API BehaviourObject(BehaviourObject &&other) = delete;
	ENGINE_API BehaviourObject &operator=(BehaviourObject const& other) = delete;
	ENGINE_API BehaviourObject &operator=(BehaviourObject &&other) = delete;
	ENGINE_API virtual void setParent() = 0;
	ENGINE_API virtual void handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) = 0;
	ENGINE_API virtual void start() = 0;
	ENGINE_API virtual void update() = 0;
	ENGINE_API virtual void interact(std::shared_ptr<BehaviourObject> player) = 0;
};