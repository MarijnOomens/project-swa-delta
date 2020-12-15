#pragma once

#include "GameObject.h"
#include "CollidingComponent.h"
#include <map>

class IInteractiveObject : public GameObject
{
public:
	std::map<std::string, std::string> textures;
	std::shared_ptr<CollidingComponent> cc;

	virtual void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) = 0;
private:
	std::string name;
	std::string dialogue;
};