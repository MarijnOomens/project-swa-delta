#pragma once
#include <iostream>
#include "main.h"

class Vector2D
{
public:
	int x;
	int y;

	ENGINE_API Vector2D();
	ENGINE_API Vector2D(int x, int y);

	ENGINE_API Vector2D& add(const Vector2D& vec);
	ENGINE_API Vector2D& subtract(const Vector2D& vec);
	ENGINE_API Vector2D& multiply(const Vector2D& vec);
	ENGINE_API Vector2D& divide(const Vector2D& vec);
};