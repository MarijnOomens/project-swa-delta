#pragma once
#include <string>
#include <stdbool.h>

class ParserData {

public:
	ParserData();
	~ParserData();

	ParserData(const std::string x, const std::string y, const std::string tileId);
	std::string x, y, tileId;
	bool isCollider = false;
};