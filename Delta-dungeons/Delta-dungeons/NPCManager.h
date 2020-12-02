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
	std::map<std::string, std::shared_ptr<IInteractiveObject>> npcs;
	std::vector<std::string> parsedNpcs;

	NPCManager();
	~NPCManager() {}

	void createNPC(std::string levelName);
	std::map<std::string, std::string> passTextures() const;

	void addTrainers();
	int getRandomNPC();
private:
	std::shared_ptr<GameObjectBuilder> builder;
};