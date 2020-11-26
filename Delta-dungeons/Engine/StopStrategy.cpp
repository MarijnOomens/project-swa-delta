#include "StopStrategy.h"

StopStrategy::StopStrategy() {}

StopStrategy::~StopStrategy() {}

void StopStrategy::actCollision(std::shared_ptr<ColliderComponent> collider, int x, int y, KeyCodes direction)
{
	std::cout << "stop... hammer time " << std::endl;
}
