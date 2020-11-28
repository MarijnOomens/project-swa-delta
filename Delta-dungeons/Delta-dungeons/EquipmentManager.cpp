#include "EquipmentManager.h"

EquipmentManager::EquipmentManager()
{
	builder = std::make_shared<GameObjectBuilder>();
}

void EquipmentManager::createEquipment(std::string levelName)
{
	std::unique_ptr<XMLSceneParser> xmlSceneParser = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<ParserData>> equipmentData = xmlSceneParser->getEquipmentDataList("Assets/Maps/"+ levelName + "/level.xml");

	for (auto parsedEquipment : equipmentData)
	{
		if (parsedEquipment->tileId == "3") 
		{
			equipments.try_emplace("pokeball" + parsedEquipment->x + parsedEquipment->y, builder->getEquipment(std::stoi(parsedEquipment->x), std::stoi(parsedEquipment->y), "pokeball"));
		}
		else if (parsedEquipment->tileId == "4") 
		{
			equipments.try_emplace("running_shoes" + parsedEquipment->x + parsedEquipment->y, builder->getEquipment(std::stoi(parsedEquipment->x), std::stoi(parsedEquipment->y), "running_shoes"));
		}
		else if (parsedEquipment->tileId == "5") 
		{
			equipments.try_emplace("berry" + parsedEquipment->x + parsedEquipment->y, builder->getEquipment(std::stoi(parsedEquipment->x), std::stoi(parsedEquipment->y), "berry"));
		}
		else if (parsedEquipment->tileId == "6") 
		{
			equipments.try_emplace("boomerang" + parsedEquipment->x + parsedEquipment->y, builder->getEquipment(std::stoi(parsedEquipment->x), std::stoi(parsedEquipment->y), "boomerang"));
		}
	}
}

std::map<std::string, std::string> EquipmentManager::passTextures() const
{
	std::map<std::string, std::string> totalTextures;
	for (auto& equipment : equipments) 
	{
		for (auto& t : equipment.second->textures) 
		{
			totalTextures.try_emplace(t.first, t.second);
		}
	}
	return totalTextures;
}