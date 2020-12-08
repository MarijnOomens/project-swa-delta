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
#include "NPCParserData.h"

class NPCFactory : public GameObjectFactory
{
public:
	std::map<std::string, std::shared_ptr<IInteractiveObject>> npcs;
	std::vector<std::shared_ptr<NPCParserData>> parsedNpcs;

	NPCFactory();
	~NPCFactory() {}

	void createNPCs(const std::string& levelName);
	std::map<std::string, std::string> passTextures() const;

	int getRandomNPC();
private:
	std::shared_ptr<GameObjectBuilder> builder;
};