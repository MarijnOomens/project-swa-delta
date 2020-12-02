#pragma once

#include <vector>
#include "IInteractiveObject.h"

class InteractiveManager {
public:
	void createBaseInteractive();

private:
	std::vector<IInteractiveObject> pokemon;
	std::vector<IInteractiveObject> NPC;
	std::vector<IInteractiveObject> puzzleObjects;
};