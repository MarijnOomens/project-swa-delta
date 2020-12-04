#pragma once
#include <string>
class NPCParserData
{
public:
	std::string name, dialogue;

	NPCParserData(const std::string& name, const std::string& dialogue);
	~NPCParserData() {}
};

