#pragma once
#include <string>
#include <map>
#include "InteractiveObject.h"

class NPC : InteractiveObject
{

protected:
	std::string sfxPath;

private:
	std::string name;
	std::map<std::string, std::string> dialogue;
};