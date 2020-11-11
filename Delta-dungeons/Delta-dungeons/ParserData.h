#pragma once
#include <string>

class ParserData {

public:
	ParserData() {};
	~ParserData() {};

	ParserData(const std::string& x, const std::string& y, const std::string& tileId);
	std::string x, y, tileId;
};