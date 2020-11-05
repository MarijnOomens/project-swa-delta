#include "NPCManager.h"

NPCManager::NPCManager() 
{
}

NPCManager::~NPCManager() {}


void NPCManager::createNPC() 
{
	std::shared_ptr<NPC> leaf = std::make_shared<NPC>(192, 192, "npc");
	leaf->textures.try_emplace("npc", "Assets/player_anims.png");
	npcs.try_emplace("leaf", leaf);

	std::shared_ptr<NPC> leaf2 = std::make_shared<NPC>(288, 480, "npc");
	npcs.try_emplace("leaf2", leaf2);

	std::shared_ptr<NPC> leaf3 = std::make_shared<NPC>(192, 480, "npc");
	npcs.try_emplace("leaf3", leaf3);

	std::shared_ptr<Pokemon> shinx = std::make_shared<Pokemon>(128, 480, "shinx");
	shinx->textures.try_emplace("shinx", "Assets/Pokemon/shinx_anims.png");
	npcs.try_emplace("shinx", shinx);

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