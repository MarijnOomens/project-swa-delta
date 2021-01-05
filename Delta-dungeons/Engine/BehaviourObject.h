#pragma once

#include "main.h"
#include "Transform.h"
#include "Keycodes.h"
#include "KeyboardEvent.h"
#include <iostream>

/// <summary>
/// BehviourObject is the base class in the GameObject + components composite pattern. The GameObject class as well as the different
/// component derive from this class to base their functionality upon.
/// </summary>
class BehaviourObject : public std::enable_shared_from_this<BehaviourObject> {
public:
	Transform transform;

	ENGINE_API BehaviourObject();
	ENGINE_API virtual ~BehaviourObject()= default;
	ENGINE_API BehaviourObject(BehaviourObject const& other) = delete;
	ENGINE_API BehaviourObject(BehaviourObject &&other) = delete;
	ENGINE_API BehaviourObject &operator=(BehaviourObject const& other) = delete;
	ENGINE_API BehaviourObject &operator=(BehaviourObject &&other) = delete;
	/// <summary>
	/// Sets another BehaviourObject as parent
	/// </summary>
	ENGINE_API virtual void setParent() = 0;
	/// <summary>
	/// Gets called every time the scene this BehaviourObject is in receives input. Keycodes and mouse position can be used to
	/// handle the given input.
	/// </summary>
	ENGINE_API virtual void handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) = 0;
	/// <summary>
	/// Gets called when the scene this BehaviourObject is in is initialised, so can be used for functions to be called only
	/// when the scene is loaded
	/// </summary>
	ENGINE_API virtual void start() = 0;
	/// <summary>
	/// Gets called every game tick when the scene that this BehaviourObject is in is loaded in
	/// </summary>
	ENGINE_API virtual void update(int time) = 0;
	/// <summary>
	/// Gets called when a gameobject triggers an interaction with this BehaviourObject
	/// </summary>
	ENGINE_API virtual void interact(std::shared_ptr<BehaviourObject> player) = 0;
};