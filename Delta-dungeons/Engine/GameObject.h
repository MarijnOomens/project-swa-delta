#pragma once

#include "BehaviourObject.h"
#include <vector>
#include "main.h"
/// <summary>
/// GameObject is the base class for all objects within the game that require behaviour.
/// </summary>
/// If a class derives from GameObject, it can override functions such as start, update, interact and handleinput. It is also possible
/// to register components to a gameobject to give it extra functionality such as a GraphicsComponent fro graphics rendering.
class GameObject : public BehaviourObject {
public:
	std::vector<std::shared_ptr<BehaviourObject>> components;

	ENGINE_API GameObject() {}

	ENGINE_API virtual void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) = 0;

	/// <summary>
	/// This method returns a list of all gameObjects within a gameObject. The method is recursive to get all underlying objects.
	/// </summary>
	/// <returns>Returns a vector of all objects under this gameObject.</returns>
	ENGINE_API std::vector<std::shared_ptr<BehaviourObject>> getComponentsRecursive();
};