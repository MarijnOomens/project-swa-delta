#include "PushStrategy.h"

//voeg canPush toe
void PushStrategy::actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction)
{
	if (collider != nullptr)
	{
		//canpush is false in registercollision
	}
	auto col = dynamic_cast<IInteractiveObject*>(collider.get());
	col->registerCollision(x, y, true, false, false);
}
