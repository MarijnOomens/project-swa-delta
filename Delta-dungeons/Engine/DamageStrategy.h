#pragma once
#include <memory>
#include "CollisionStrategy.h"
#include "InteractiveObject.h"

class DamageStrategy : public CollisionStrategy
{
public:
    ENGINE_API DamageStrategy();
    ENGINE_API ~DamageStrategy();

    ENGINE_API void actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction) override;

private:
}; 
