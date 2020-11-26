#pragma once
#include <memory>
#include "main.h"
#include "CollidingComponent.h"

class CollidingComponent;

class CollisionStrategy
{
public:    
	ENGINE_API CollisionStrategy();
	ENGINE_API virtual ~CollisionStrategy() = default;
	ENGINE_API CollisionStrategy(CollisionStrategy const& other) = delete;
	ENGINE_API CollisionStrategy(CollisionStrategy&& other) = delete;
	ENGINE_API CollisionStrategy& operator=(CollisionStrategy const& other) = delete;
	ENGINE_API CollisionStrategy& operator=(CollisionStrategy&& other) = delete;

    ENGINE_API virtual void actCollision(std::shared_ptr<CollidingComponent> collider, int x, int y, KeyCodes direction) = 0;
private:
};