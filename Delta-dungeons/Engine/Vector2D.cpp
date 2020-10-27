#include "Vector2D.h"

Vector2D::Vector2D() 
{
	x = 0;
	y = 0;
}

Vector2D::Vector2D(int x, int y) 
{
	this->x = x;
	this->y = y;
}

Vector2D& Vector2D::add(const Vector2D& vec) 
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

Vector2D& Vector2D::subtract(const Vector2D& vec) 
{
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}

Vector2D& Vector2D::multiply(const Vector2D& vec) 
{
	this->x *= vec.x;
	this->y *= vec.y;
	return *this;
}

Vector2D& Vector2D::divide(const Vector2D& vec) 
{
	this->x /= vec.x;
	this->y /= vec.y;
	return *this;
}