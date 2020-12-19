#pragma once
#include "GameObjectBuilder.h"
#include "Pokeball.h"
#include "XMLSceneParser.h"
#include "GameObjectFactory.h"
#include <string>
#include <map>
#include <memory>

class EquipmentFactory : public GameObjectFactory
{
public:
	std::shared_ptr<GameObjectBuilder> builder;
	std::map<std::string, std::shared_ptr<IEquipment>> equipments;

	EquipmentFactory();

	void createEquipment(const std::string& levelName);
	std::map<std::string, std::string> passTextures() const;
};