#pragma once
#include <memory>
#include <iostream>
#include "main.h"
#include "Keycodes.h"
#include "BehaviourObject.h"

class CollisionStrategy
{
public:    
	ENGINE_API CollisionStrategy();
	ENGINE_API virtual ~CollisionStrategy() = default;
	ENGINE_API CollisionStrategy(CollisionStrategy const& other) = delete;
	ENGINE_API CollisionStrategy(CollisionStrategy&& other) = delete;
	ENGINE_API CollisionStrategy& operator=(CollisionStrategy const& other) = delete;
	ENGINE_API CollisionStrategy& operator=(CollisionStrategy&& other) = delete;

    ENGINE_API virtual void actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y) = 0;
private:
};