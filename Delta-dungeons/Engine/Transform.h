#pragma once

#include "Vector2D.h"
#include "main.h"

class Transform {
public:
	Vector2D position;
	Vector2D rotation;
	Vector2D scale;

	ENGINE_API Transform();
};