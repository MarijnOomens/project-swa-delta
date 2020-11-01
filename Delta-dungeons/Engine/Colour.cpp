#include "Colour.h"

Colour::Colour(int r, int g, int b, int a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}
Colour::Colour() {
	this->r = 255;
	this->g = 255;
	this->b = 255;
	this->a = 255;
}