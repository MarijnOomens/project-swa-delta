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

	std::shared_ptr<Pokemon> umbreon = std::make_shared<Pokemon>(256, 192, "umbreon");
	umbreon->textures.try_emplace("umbreon", "Assets/Pokemon/umbreon_anims.png");
	npcs.try_emplace("umbreon", umbreon);


	std::shared_ptr<NPC> leaf2 = std::make_shared<NPC>(480, 480, "player");
	npcs.try_emplace("leaf2", leaf2);

	std::shared_ptr<Pokemon> dunsparce = std::make_shared<Pokemon>(544, 480, "dunsparce");
	dunsparce->textures.try_emplace("dunsparce", "Assets/Pokemon/dunsparce_anims.png");
	npcs.try_emplace("dunsparce", dunsparce);

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