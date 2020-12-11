#pragma once

#include "IInteractiveObject.h"
#include <string>

class PuzzleObject
{

	//interact add the direction
		//directions decides if either x or y gets adjusted
		//call checkcollsion(cc);
	//if hasmoved = true
		// dont move
	//else 
		//call move method within puzzleobject
		//call func method of puzzle.cpp
protected:
	std::string sfxPath;
};