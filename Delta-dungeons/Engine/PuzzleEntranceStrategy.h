#pragma once

#include "CollisionStrategy.h"
#include "IInteractiveObject.h"

class PuzzleEntranceStrategy : public CollisionStrategy
{
public:
    ENGINE_API PuzzleEntranceStrategy() {}
    ENGINE_API ~PuzzleEntranceStrategy() {}

    ENGINE_API void actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction) override;

private:
};

