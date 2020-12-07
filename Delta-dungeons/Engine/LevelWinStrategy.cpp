#include "LevelWinStrategy.h"

void LevelWinStrategy::actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction)
{
	auto col = dynamic_cast<IInteractiveObject*>(collider.get());
	col->registerCollision(x, y, false, false, true);
}