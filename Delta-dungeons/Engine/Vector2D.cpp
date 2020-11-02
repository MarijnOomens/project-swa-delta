#include "Vector2D.h"

/// <summary>
/// Vector2D holds an X and Y of an object. If empty, x and y are 0.
/// </summary>
Vector2D::Vector2D() 
{
	x = 0;
	y = 0;
}

/// <summary>
/// Vector2D holds an X and Y of an object. It sets the parameters on the X and Y
/// </summary>
/// <param name="x">The X position of the object.</param>
/// <param name="y">The Y position of the object.</param>
Vector2D::Vector2D(int x, int y) 
{
	this->x = x;
	this->y = y;
}

/// <summary>
/// Add another vectors positions onto this vectors positions.
/// </summary>
/// <param name="vec">The other vector</param>
/// <returns>A reference to this vector</returns>
Vector2D& Vector2D::add(const Vector2D& vec) 
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

/// <summary>
/// Subtracts another vectors positions from this vectors positions.
/// </summary>
/// <param name="vec">The other vector</param>
/// <returns>A reference to this vector</returns>
Vector2D& Vector2D::subtract(const Vector2D& vec) 
{
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}

/// <summary>
/// Multiplies another vectors positions with this vectors positions.
/// </summary>
/// <param name="vec">The other vector</param>
/// <returns>A reference to this vector</returns>
Vector2D& Vector2D::multiply(const Vector2D& vec) 
{
	this->x *= vec.x;
	this->y *= vec.y;
	return *this;
}

/// <summary>
/// Divides another vectors positions from this vectors positions.
/// </summary>
/// <param name="vec">The other vector</param>
/// <returns>A reference to this vector</returns>
Vector2D& Vector2D::divide(const Vector2D& vec) 
{
	this->x /= vec.x;
	this->y /= vec.y;
	return *this;
}