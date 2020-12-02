#pragma once

#include "IInteractiveObject.h"
#include <string>

class PuzzleObject : IInteractiveObject
{
protected:
	std::string sfxPath;
};