#pragma once
#include <string>
#include <vector>
class NPCParserData
{
public:
	std::string name;
	std::vector<std::string> dialogues;

	NPCParserData(const std::string& name, const std::vector<std::string> d);
	~NPCParserData() {}
};

