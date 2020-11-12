#pragma once

#include <string>
#include <map>
#include "NPC.h"
#include "Pokemon.h"
#include "GameObjectBuilder.h"
#include <memory>

class NPCManager 
{
public:
	std::map<std::string, std::shared_ptr<InteractiveObject>> npcs;

	NPCManager();
	~NPCManager() {}

	void createNPC();
	std::map<std::string, std::string> passTextures() const;

private:
	std::shared_ptr<GameObjectBuilder> builder;
};