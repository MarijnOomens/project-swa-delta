#pragma once

#include "SDL.h"

class Rectangle {
public:
	SDL_Rect source;
	SDL_Rect destination;

	Rectangle();
	~Rectangle();

	void defineSource(int x, int y, int w, int h);
	void defineDestination(int x, int y, int w, int h);
};