#pragma once
#include "main.h"

class Colour {
public:
	int r;
	int g;
	int b;
	int a;

	ENGINE_API Colour();
	ENGINE_API Colour(int r, int g, int b, int a);
};