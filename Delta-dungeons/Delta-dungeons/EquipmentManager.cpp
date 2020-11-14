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
	std::vector<std::shared_ptr<ParserData>> equipmentData = xmlSceneParser.get()->getEquipmentDataList("Assets/maps/level1.xml");

	for (auto parsedEquipment : equipmentData)
	{
		if (parsedEquipment.get()->tileId == "3") {
			equipments.try_emplace("pokeball" + parsedEquipment.get()->x + parsedEquipment.get()->y, builder.get()->getPokeball(std::stoi(parsedEquipment.get()->x), std::stoi(parsedEquipment.get()->y), "pokeball"));
		}
		else if (parsedEquipment.get()->tileId == "4") {
			equipments.try_emplace("running_shoes" + parsedEquipment.get()->x + parsedEquipment.get()->y, builder.get()->getRunningShoes(std::stoi(parsedEquipment.get()->x), std::stoi(parsedEquipment.get()->y), "running_shoes"));
		}
		else if (parsedEquipment.get()->tileId == "5") {
			equipments.try_emplace("berry" + parsedEquipment.get()->x + parsedEquipment.get()->y, builder.get()->getBerry(std::stoi(parsedEquipment.get()->x), std::stoi(parsedEquipment.get()->y), "berry"));
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

void EquipmentManager::interact(int x, int y) {
	//for (auto& equipment : equipments) {
	//	if (equipment.second.get()->transform.position.x == x && equipment.second.get()->transform.position.y == y) {
	//		std::cout << "found " << equipment.first << std::endl;
	//	}
	//}
}
