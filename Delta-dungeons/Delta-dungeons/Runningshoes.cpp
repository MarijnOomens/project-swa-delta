#include "Runningshoes.h"
#include <iostream>
Runningshoes::Runningshoes() {

}

Runningshoes::~Runningshoes() {

}

void Runningshoes::use() {
	isActivated = !isActivated;
	std::cout << isActivated << std::endl;
}