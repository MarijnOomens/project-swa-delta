#pragma once
#include "GameObjectBuilder.h"
#include "Pokeball.h"
#include "XMLSceneParser.h"
#include <string>
#include <map>
#include <memory>

class EquipmentManager
{
public:
	std::shared_ptr<GameObjectBuilder> builder;
	std::map<std::string, std::shared_ptr<IEquipment>> equipments;

	EquipmentManager();
	~EquipmentManager() {}

	void createEquipment(std::string levelName);
	std::map<std::string, std::string> passTextures() const;
};