#pragma once
#include "CollisionStrategy.h"
#include "IInteractiveObject.h"
class TransitionStrategy : public CollisionStrategy
{
public:
    ENGINE_API TransitionStrategy(){}
    ENGINE_API ~TransitionStrategy(){}

    ENGINE_API void actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction) override;

private:
};

