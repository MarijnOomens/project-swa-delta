#pragma once
#include <iostream>
#include "main.h"


class Vector2D
{
public:
	int x;
	int y;

	int spriteLocationInPNGWidth;
	int spriteLocationInPNGHeight;
	ENGINE_API Vector2D();
	ENGINE_API Vector2D(int x, int y);

	Vector2D& Add(const Vector2D& vec);
	Vector2D& Subtract(const Vector2D& vec);
	Vector2D& Multiply(const Vector2D& vec);
	Vector2D& Divide(const Vector2D& vec);
};