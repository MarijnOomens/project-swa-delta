#pragma once

#include "SDL.h"

class Rectangle {
public:
	Rectangle();
	~Rectangle();

	SDL_Rect source;
	SDL_Rect destination;

	void defineSource(int x, int y, int w, int h);
	void defineDestination(int x, int y, int w, int h);

	void init();
private:
};