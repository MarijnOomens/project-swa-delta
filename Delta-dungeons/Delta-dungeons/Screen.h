#pragma once
#include <string>
#include <vector>
#include "GraphicsComponent.h"

class Screen 
{
public:
	virtual void closeScreen() = 0;
	std::string text;
	std::vector<BehaviourObject> Objects;
	GraphicsComponent* gc;
	virtual std::vector<BehaviourObject> getBehaviourObjects() = 0;
};