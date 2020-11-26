#include <memory>
#include "ColliderComponent.h"
#include "Strategy.h"

class StopStrategy : public Strategy
{
public:
    StopStrategy() {}
    ~StopStrategy() {}

    void actCollision(std::shared_ptr<ColliderComponent> collider, int x, int y, KeyCodes direction) override;

private:
};