#include "Rectangle.h"

/// <summary>
/// The Rectangle class is used to make a square out of a X and Y and Width and Height.
/// </summary>
Rectangle::Rectangle()
{
	destination = { 0,0,0,0 };
	source = { 0,0,0,0 };
}

/// <summary>
/// DefineSource sets the Width and Height and X and Y of the source Rectangle.
/// </summary>
/// <param name="x">The X position.</param>
/// <param name="y">The Y position.</param>
/// <param name="w">The width in numbers.</param>
/// <param name="h">The height in numbers.</param>
void Rectangle::defineSource(const int x, const int y, const int w, const int h)
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
void Rectangle::defineDestination(const int x, const int y, const int w, const int h)
{
	destination.x = x;
	destination.y = y;
	destination.w = w;
	destination.h = h;
}