#pragma once
#include "InteractiveObject.h"
#include <string>
#include <map>

class NPC : InteractiveObject
{
protected:
	std::string sfxPath;
private:
	std::string name;
	std::map<std::string, std::string> dialogue;
};