#pragma once
#include <memory>
#include "CollidingComponent.h"
#include "CollisionStrategy.h"

class CollidingComponent;
class CollisionStrategy;

class StopStrategy : public CollisionStrategy
{
public:
    StopStrategy();
    ~StopStrategy();

    void actCollision(std::shared_ptr<CollidingComponent> collider, int x, int y, KeyCodes direction) override;

private:
};