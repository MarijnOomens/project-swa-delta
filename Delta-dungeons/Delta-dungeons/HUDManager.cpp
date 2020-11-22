#include "HUDManager.h"

void HUDManager::createHud()
{
	hud = std::make_shared<HUD>(3);
}

void HUDManager::addItem(const std::string& texturePath)
{
	hud->addItem(texturePath);
}

std::map<std::string, std::string> HUDManager::passTextures() const
{
	std::map<std::string, std::string> totalTextures;
	for (auto& t : hud->textures) 
	{
		totalTextures.emplace(t.first, t.second);
	}
	return totalTextures;
}

void HUDManager::updateHUDHealth (bool hit)
{
	hud->updateHealth(hit);
}