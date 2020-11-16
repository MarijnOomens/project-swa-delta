#include "NPCManager.h"

NPCManager::NPCManager() 
{
	builder = std::make_shared<GameObjectBuilder>();
}

void NPCManager::createNPC() 
{
	npcs.emplace("bugtrainer", builder->getNPC(640, 896, "bugtrainer"));
}

std::map<std::string, std::string> NPCManager::passTextures() const
{
	std::map<std::string, std::string> totalTextures;
	for (auto& npc : npcs) {
		for (auto& t : npc.second->textures) {
			totalTextures.emplace(t.first, t.second);
		}
	}
	return totalTextures;
}