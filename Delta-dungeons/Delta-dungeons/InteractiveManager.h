#pragma once

#include <vector>
#include "InteractiveObject.h"

class InteractiveManager {
public:
	void createBaseInteractive();

private:
	std::vector<InteractiveObject> pokemon;
	std::vector<InteractiveObject> NPC;
	std::vector<InteractiveObject> puzzleObjects;
};