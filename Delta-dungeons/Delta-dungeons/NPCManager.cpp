#include "NPCManager.h"

NPCManager::NPCManager() 
{
	builder = std::make_shared<GameObjectBuilder>();
}

NPCManager::~NPCManager() {}


void NPCManager::createNPC() 
{
	npcs.try_emplace("bugtrainer", builder.get()->getNPC(640, 896, "bugtrainer"));
	npcs.try_emplace("eevee", builder.get()->getPokemon(768, 896, "eevee"));
	npcs.try_emplace("flareon", builder.get()->getPokemon(896, 896, "flareon"));
	npcs.try_emplace("vaporeon", builder.get()->getPokemon(1024, 896, "vaporeon"));
	npcs.try_emplace("jolteon", builder.get()->getPokemon(1152, 896, "jolteon"));
	npcs.try_emplace("espeon", builder.get()->getPokemon(1280, 896, "espeon"));
	npcs.try_emplace("umbreon", builder.get()->getPokemon(1408, 896, "umbreon"));
	npcs.try_emplace("leafeon", builder.get()->getPokemon(1536, 896, "leafeon"));
	npcs.try_emplace("glaceon", builder.get()->getPokemon(1664, 896, "glaceon"));
	npcs.try_emplace("sylveon", builder.get()->getPokemon(1792, 896, "sylveon"));
}

std::map<std::string, std::string> NPCManager::passTextures() const
{
	std::map<std::string, std::string> totalTextures;
	for (auto& npc : npcs) {
		for (auto& t : npc.second->textures) {
			totalTextures.try_emplace(t.first, t.second);
		}
	}
	return totalTextures;
}