#include "Runningshoes.h"
#include <iostream>

/// <summary>
/// This class is an equipment that can be used to increase the movement speed.
/// </summary>
Runningshoes::Runningshoes() 
{
}

Runningshoes::Runningshoes(const cbFunction f, void* p) : func(f), pointer(p) {}

Runningshoes::~Runningshoes() {}

/// <summary>
/// This method gets called to change the isActivated boolean property. 
/// Afterwards it will pass the isActivated boolean to the Player.cpp class.
/// </summary>
void Runningshoes::use()
{
	isActivated = !isActivated;
	std::cout << isActivated << std::endl;
	func(pointer, isActivated);
}