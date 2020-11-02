#include "Colour.h"

/// <summary>
/// This constructor initializes the colour on white.
/// </summary>
Colour::Colour() {
	this->r = 255;
	this->g = 255;
	this->b = 255;
	this->a = 255;
}

/// <summary>
/// This class sets a colour based on the parameters given.
/// </summary>
/// <param name="r">The red value in RGB.</param>
/// <param name="g">The green value in RGB.</param>
/// <param name="b">The blue value in RGB.</param>
/// <param name="a">The alpha value in RGB.</param>
Colour::Colour(int r, int g, int b, int a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}