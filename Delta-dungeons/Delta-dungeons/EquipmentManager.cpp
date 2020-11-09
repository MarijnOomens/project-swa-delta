#include "EquipmentManager.h"
#include "XMLSceneParser.h"
EquipmentManager::EquipmentManager()
{
	builder = std::make_shared<GameObjectBuilder>();
}

EquipmentManager::~EquipmentManager() {}

void EquipmentManager::createEquipment()
{
	std::unique_ptr<XMLSceneParser> parsedDatas = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<Pokeball>> createdEquipments;

	for (std::shared_ptr<ParserData> equipment : parsedDatas.get()->getEquipmentDataList("Assets/Level/collidermap.xml"))
	{
		int first = equipment.get()->tileId[0] - 48;

		if (equipment.get()->tileId[1]) {
			int second = equipment.get()->tileId[1] - 48;
			createdEquipments.push_back(std::make_shared<Pokeball>(std::stoi(equipment.get()->x), std::stoi(equipment.get()->y), first, second, true, std::stoi(equipment.get()->tileId)));
		}
		else
		{
			createdEquipments.push_back(std::make_shared<Pokeball>(std::stoi(equipment.get()->x), std::stoi(equipment.get()->y), first, true, std::stoi(equipment.get()->tileId)));
		}
	}


	//return tileMap;
}

std::map<std::string, std::string> EquipmentManager::passTextures() const
{
	std::map<std::string, std::string> texture;
	texture.try_emplace("Level1", "Assets/Tileset/tileset-1.png");
	return texture;
}
