#pragma once
#include "NPC.h"
#include "Pokemon.h"
#include "GameObjectBuilder.h"
#include "XMLSceneParser.h"
#include <string>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>

class NPCManager
{
public:
	std::vector<std::string> trainerList;
	std::map<std::string, std::shared_ptr<IInteractiveObject>> npcs;

	NPCManager();
	~NPCManager() {}

	void createNPC(std::string levelName);
	std::map<std::string, std::string> passTextures() const;

	void addTrainers();
	std::string getRandomNPC();
private:
	std::shared_ptr<GameObjectBuilder> builder;
};