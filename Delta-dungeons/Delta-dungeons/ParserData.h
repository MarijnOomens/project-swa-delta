#pragma once

#include <string>

class ParserData {

public:
	std::string x, y, tileId;
	bool isCollider = false;
	bool isTrigger = false;
	bool isWinTrigger = false;
	bool isPuzzleEntrance = false;
	bool isPuzzleExit = false;

	ParserData() {}
	~ParserData() {}

	ParserData(const std::string& x, const std::string& y, const std::string& tileId);
};