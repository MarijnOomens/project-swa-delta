#pragma once
#include <string>
#include <map>

class NPC
{

protected:
	std::string sfxPath;

private:
	std::string name;
	std::map<std::string, std::string> dialogue;
};