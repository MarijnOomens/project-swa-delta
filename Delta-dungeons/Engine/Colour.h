#pragma once
#include "main.h"

class Colour {
public:
	ENGINE_API Colour(int r, int g, int b, int a);
	ENGINE_API Colour();
	int r;
	int g;
	int b;
	int a;
};