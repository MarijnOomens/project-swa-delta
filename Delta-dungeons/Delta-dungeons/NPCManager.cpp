#include "NPCManager.h"

NPCManager::NPCManager()
{
	builder = std::make_shared<GameObjectBuilder>();
}

void NPCManager::createNPC(std::string levelName)
{
	npcs.clear();
	std::unique_ptr<XMLSceneParser> parser = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<ParserData>> npcTile = parser->getNPCDataList("Assets/Map/" + levelName + "/level.xml");
	parsedNpcs = parser->loadNPC("Assets/Map/" + levelName + "/npc.xml");
	srand(time(0));
	for (auto parsedTile : npcTile)
	{
		if (parsedTile->tileId == "1") {
			std::shared_ptr<NPCParserData> n = parsedNpcs[getRandomNPC()];
			npcs.emplace(n->name + std::to_string(npcs.size()), builder->getNPC(std::stoi(parsedTile->x), std::stoi(parsedTile->y), n->name, n->dialogues));
		}
	}
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

int NPCManager::getRandomNPC()
{
	int randomNpc = rand() % (parsedNpcs.size());
	return randomNpc;
}
