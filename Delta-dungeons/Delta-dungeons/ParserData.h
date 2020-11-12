#pragma once

#include <string>

class ParserData {

public:
	std::string x, y, tileId;

	ParserData() {}
	~ParserData() {}

	ParserData(const std::string& x, const std::string& y, const std::string& tileId);
};