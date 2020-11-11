#pragma once

#include "SDL.h"

class Rectangle 
{
public:
	Rectangle();
	~Rectangle() {}

	void defineSource(int x, int y, int w, int h);
	void defineDestination(int x, int y, int w, int h);

private:
	SDL_Rect source;
	SDL_Rect destination;
};