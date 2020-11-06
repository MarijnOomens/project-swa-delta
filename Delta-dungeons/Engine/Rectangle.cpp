#include "Rectangle.h"

/// <summary>
/// The Rectangle class is used to make a square out of a X and Y and Width and Height.
/// </summary>
Rectangle::Rectangle()
{
	destination = SDL_Rect();
	source = SDL_Rect();
}

Rectangle::~Rectangle() {}

/// <summary>
/// DefineSource sets the Width and Height and X and Y of the source Rectangle.
/// </summary>
/// <param name="x">The X position.</param>
/// <param name="y">The Y position.</param>
/// <param name="w">The width in numbers.</param>
/// <param name="h">The height in numbers.</param>
void Rectangle::defineSource(int x, int y, int w, int h)
{
	source.x = x;
	source.y = y;
	source.w = w;
	source.h = h;
}

/// <summary>
/// DefineDestination sets the Width and Height and X and Y of the destination Rectangle.
/// </summary>
/// <param name="x">The X position.</param>
/// <param name="y">The Y position.</param>
/// <param name="w">The width in numbers.</param>
/// <param name="h">The height in numbers.</param>
void Rectangle::defineDestination(int x, int y, int w, int h)
{
	destination.x = x;
	destination.y = y;
	destination.w = w;
	destination.h = h;
}