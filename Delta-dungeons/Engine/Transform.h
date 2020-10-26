#pragma once
#include "Vector2D.h"


class Transform {
public:
	Transform();
	Vector2D position;
	Vector2D rotation;
	Vector2D scale;
	Vector2D spriteLocationInPNG;
};