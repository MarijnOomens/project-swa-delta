#pragma once
#include "IInteractiveObject.h"
#include "CollidingComponent.h"
#include <string>
#include <map>
#include <GraphicsComponent.h>
#include "StopStrategy.h"

class NPC : public IInteractiveObject
{
public:
	NPC(int x, int y, std::string& texture);

	void interact() override;
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned) override;

protected:
	std::string sfxPath;

private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	const int animationSpeed = 130;
};