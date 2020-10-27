#include "Runningshoes.h"
#include <iostream>

Runningshoes::Runningshoes() {}

Runningshoes::Runningshoes(const cbFunction f, void* p) : func(f), pointer(p) {}

Runningshoes::~Runningshoes() {}

void Runningshoes::use()
{
	isActivated = !isActivated;
	std::cout << isActivated << std::endl;
	func(pointer, isActivated);
}