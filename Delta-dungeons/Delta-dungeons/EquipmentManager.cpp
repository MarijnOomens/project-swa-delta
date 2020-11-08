#include "EquipmentManager.h"

EquipmentManager::EquipmentManager()
{
	builder = std::make_shared<GameObjectBuilder>();
}

EquipmentManager::~EquipmentManager() {}

void EquipmentManager::createEquipment()
{
	//builder.getEquipment(x,y,tileset, tileId)
}

//std::map<std::string, std::string> EquipmentManager::passTextures() const
//{
//
//}
