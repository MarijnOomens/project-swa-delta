#include "NPCManager.h"

NPCManager::NPCManager()
{
	builder = std::make_shared<GameObjectBuilder>();
	trainerList = std::vector<std::string>();
	addTrainers();
}

void NPCManager::createNPC(std::string levelName)
{
	std::unique_ptr<XMLSceneParser> xmlSceneParser = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<ParserData>> npcData = xmlSceneParser->getNPCDataList("Assets/Maps/"+ levelName + "/level.xml");
	srand(time(0));
	for (auto parsedNPC : npcData)
	{
		if (parsedNPC->tileId == "1") {
			std::string trainer = getRandomNPC();
			npcs.try_emplace(trainer + parsedNPC->x + parsedNPC->y, builder->getNPC(std::stoi(parsedNPC->x), std::stoi(parsedNPC->y), trainer));
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

void NPCManager::addTrainers()
{
	trainerList.push_back("bugtrainer");
	trainerList.push_back("youngster");
	trainerList.push_back("acetrainer_m");
	trainerList.push_back("acetrainer_f");
}

std::string NPCManager::getRandomNPC()
{
	int randomTrainer = rand() % trainerList.size();
	return trainerList.at(randomTrainer);
}
