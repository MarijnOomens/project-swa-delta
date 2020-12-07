#pragma once
#include <memory>
#include "CollisionStrategy.h"
#include "IInteractiveObject.h"

class PushStrategy : public CollisionStrategy
{
public:
    ENGINE_API PushStrategy() {}
    ENGINE_API ~PushStrategy() {}

    ENGINE_API void actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction) override;

private:
};
