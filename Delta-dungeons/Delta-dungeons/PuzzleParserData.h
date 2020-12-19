#pragma once
#include <string>
#include "Vector2D.h"
class PuzzleParserData {

public:
	Vector2D leftUp;
	Vector2D rightUp;
	Vector2D leftDown;
	Vector2D rightDown;

	PuzzleParserData(int leftUpX, int leftUpY);
	~PuzzleParserData() {}

};