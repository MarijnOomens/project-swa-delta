#pragma once

#include "Vector2D.h"

class Transform {
public:
	Vector2D position;
	Vector2D rotation;
	Vector2D scale;
	Vector2D spriteLocationInPNG;

	Transform();
};