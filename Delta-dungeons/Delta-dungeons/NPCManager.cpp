#include "NPCManager.h"

NPCManager::NPCManager() 
{
	builder = std::make_shared<GameObjectBuilder>();
}

NPCManager::~NPCManager() {}


void NPCManager::createNPC() 
{
	npcs.try_emplace("bugtrainer", builder.get()->getNPC(192, 192, "bugtrainer"));
	npcs.try_emplace("umbreon", builder.get()->getPokemon(256, 192, "umbreon"));
	//npcs.try_emplace("leaf2", builder.get()->getNPC(480, 480, "npc"));
	npcs.try_emplace("dunsparce", builder.get()->getPokemon(544, 480, "dunsparce"));
	npcs.try_emplace("shinx", builder.get()->getPokemon(128, 480, "shinx"));
	npcs.try_emplace("eevee", builder.get()->getPokemon(256, 320, "eevee"));
	npcs.try_emplace("turtwig", builder.get()->getPokemon(128, 192, "turtwig"));
	npcs.try_emplace("magmortar", builder.get()->getPokemon(320, 480, "magmortar"));
	npcs.try_emplace("ralts", builder.get()->getPokemon(320, 544, "ralts"));
	npcs.try_emplace("deoxys_standard", builder.get()->getPokemon(608, 608, "deoxys_standard"));
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