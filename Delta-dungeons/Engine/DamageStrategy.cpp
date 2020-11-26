#include "DamageStrategy.h"

DamageStrategy::DamageStrategy() {}

DamageStrategy::~DamageStrategy() {}

void DamageStrategy::actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction)
{
	std::cout << "OUCH!" << std::endl;
}
