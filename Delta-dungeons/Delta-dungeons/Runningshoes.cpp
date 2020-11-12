#include "Runningshoes.h"

/// <summary>
/// This class is an equipment that can be used to increase the movement speed.
/// </summary>
Runningshoes::Runningshoes(const cbFunction f, void* p) : func(f), pointer(p) {}

/// <summary>
/// This method gets called to change the isActivated boolean property. 
/// Afterwards it will pass the isActivated boolean to the Player.cpp class.
/// </summary>
void Runningshoes::use()
{
	isActivated = !isActivated;
	func(pointer, isActivated);
}