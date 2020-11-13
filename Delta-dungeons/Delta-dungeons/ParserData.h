#pragma once

#include <string>
#include <stdbool.h>

class ParserData {

public:
	std::string x, y, tileId;
	bool isCollider = false;

	ParserData() {}
	~ParserData() {}

	ParserData(const std::string& x, const std::string& y, const std::string& tileId);
};