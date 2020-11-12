#pragma once

#include "SDL.h"

class Rectangle 
{
public:
	Rectangle();
	~Rectangle() {}

	void defineSource(const int x, const int y, const int w,const int h);
	void defineDestination(const int x, const int y, const int w, const int h);

private:
	SDL_Rect source;
	SDL_Rect destination;
};