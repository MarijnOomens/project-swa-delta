#include "EquipmentManager.h"
#include "XMLSceneParser.h"

EquipmentManager::EquipmentManager()
{
	builder = std::make_shared<GameObjectBuilder>();
}

EquipmentManager::~EquipmentManager() {}

void EquipmentManager::createEquipment()
{
	std::unique_ptr<XMLSceneParser> xmlSceneParser = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<ParserData>> equipmentData = xmlSceneParser.get()->getEquipmentDataList("Assets/Level/level1.xml");
	
	for (auto parsedEquipment : equipmentData)
	{
		if (parsedEquipment.get()->tileId == "3") {
			equipments.try_emplace("pokeball" + parsedEquipment.get()->x + parsedEquipment.get()->y, builder.get()->getEquipment(std::stoi(parsedEquipment.get()->x), std::stoi(parsedEquipment.get()->y), "pokeball"));
		}
	}
}

std::map<std::string, std::string> EquipmentManager::passTextures() const
{
	std::map<std::string, std::string> totalTextures;
	for (auto& equipment : equipments) {
		for (auto& t : equipment.second->textures) {
			totalTextures.try_emplace(t.first, t.second);
		}
	}
	return totalTextures;
}