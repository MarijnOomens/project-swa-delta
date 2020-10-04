#include "Rectangle.h"

void Rectangle::defineSource(int x, int y, int w, int h) {
	source.x = x;
	source.y = y;
	source.w = w;
	source.h = h;
}

void Rectangle::defineDestination(int x, int y, int w, int h) {
	destination.x = x;
	destination.y = y;
	destination.w = w;
	destination.h = h;
}