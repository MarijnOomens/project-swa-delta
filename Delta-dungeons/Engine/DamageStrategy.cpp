#include "DamageStrategy.h"

void DamageStrategy::actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y)
{
	auto col = dynamic_cast<InteractiveObject*>(collider.get());
	col->registerCollision(x, y, true, false);
}
