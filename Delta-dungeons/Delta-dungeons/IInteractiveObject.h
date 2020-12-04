#pragma once

#include "GameObject.h"
#include "CollidingComponent.h"
#include <map>

class IInteractiveObject : public GameObject
{
public:
	std::map<std::string, std::string> textures;

	virtual void registerCollision(int x, int y, bool isDamaged, bool isTransitioned) = 0;
	std::shared_ptr<CollidingComponent> cc;
private:
	std::string name;
	std::string dialogue;
};