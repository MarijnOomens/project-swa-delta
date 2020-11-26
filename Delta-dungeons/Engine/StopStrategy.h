#pragma once
#include <memory>
#include "CollisionStrategy.h"

class StopStrategy : public CollisionStrategy
{
public:
    ENGINE_API StopStrategy();
    ENGINE_API ~StopStrategy();

    ENGINE_API void actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction) override;

private:
};