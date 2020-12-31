#pragma once

#include "GameObject.h"
#include "CollidingComponent.h"
#include <map>

class IInteractiveObject : public GameObject
{
public:
	std::map<std::string, std::string> textures;
	std::map<std::string, std::string> beats;
	std::shared_ptr<CollidingComponent> cc;

private:
	std::string name;
	std::string dialogue;
};