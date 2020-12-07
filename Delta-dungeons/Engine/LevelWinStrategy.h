#pragma once

#include "CollisionStrategy.h"
#include "IInteractiveObject.h"

class LevelWinStrategy : public CollisionStrategy
{
public:
    ENGINE_API LevelWinStrategy() {}
    ENGINE_API ~LevelWinStrategy() {}

    ENGINE_API void actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction) override;

private:
};

