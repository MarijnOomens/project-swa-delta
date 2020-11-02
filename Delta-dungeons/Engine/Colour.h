#pragma once
#include "main.h"

class Colour {
public:
	ENGINE_API Colour();
	ENGINE_API Colour(int r, int g, int b, int a);
	int r;
	int g;
	int b;
	int a;
};