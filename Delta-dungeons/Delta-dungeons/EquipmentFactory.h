#pragma once
#include "GameObjectBuilder.h"
#include "Pokeball.h"
#include "XMLSceneParser.h"
#include <string>
#include <map>
#include <memory>

class EquipmentFactory : public GameObjectFactory
{
public:
	std::shared_ptr<GameObjectBuilder> builder;
	std::map<std::string, std::shared_ptr<IEquipment>> equipments;

	EquipmentFactory();
	~EquipmentFactory() {}

	void createEquipment(std::string levelName);
	std::map<std::string, std::string> passTextures() const;
};