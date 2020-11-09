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
	std::vector<std::shared_ptr<ParserData>> parserData = xmlSceneParser.get()->getEquipmentDataList("Assets/Level/level1.xml");
	
	for (auto parsedEquipment : parserData)
	{
		int first = parsedEquipment.get()->tileId[0] - 48;
		if (parsedEquipment.get()->tileId[1]) {
			int second = parsedEquipment.get()->tileId[1] - 48;
			std::shared_ptr<Pokeball> pokeball = std::make_shared<Pokeball>(std::stoi(parsedEquipment.get()->x), std::stoi(parsedEquipment.get()->y), first, second, true, std::stoi(parsedEquipment.get()->tileId));
			equipments.emplace_back(pokeball);
		}
		else
		{
			std::shared_ptr<Pokeball> pokeball = std::make_shared<Pokeball>(std::stoi(parsedEquipment.get()->x), std::stoi(parsedEquipment.get()->y), first, true, std::stoi(parsedEquipment.get()->tileId));

			equipments.emplace_back(pokeball);
		}
	}
}

std::map<std::string, std::string> EquipmentManager::passTextures() const
{
	std::map<std::string, std::string> texture;
	texture.try_emplace("Level1", "Assets/Tileset/tileset-1.png");
	return texture;
}
