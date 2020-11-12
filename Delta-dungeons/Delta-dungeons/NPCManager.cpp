#include "NPCManager.h"

NPCManager::NPCManager() 
{
	builder = std::make_shared<GameObjectBuilder>();
}

void NPCManager::createNPC() 
{
	npcs.emplace("bugtrainer", builder->getNPC(640, 896, "bugtrainer"));
	npcs.emplace("eevee", builder->getPokemon(768, 896, "eevee"));
	npcs.emplace("flareon", builder->getPokemon(896, 896, "flareon"));
	npcs.emplace("vaporeon", builder->getPokemon(1024, 896, "vaporeon"));
	npcs.emplace("jolteon", builder->getPokemon(1152, 896, "jolteon"));
	npcs.emplace("espeon", builder->getPokemon(1280, 896, "espeon"));
	npcs.emplace("umbreon", builder->getPokemon(1408, 896, "umbreon"));
	npcs.emplace("leafeon", builder->getPokemon(1536, 896, "leafeon"));
	npcs.emplace("glaceon", builder->getPokemon(1664, 896, "glaceon"));
	npcs.emplace("sylveon", builder->getPokemon(1792, 896, "sylveon"));
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