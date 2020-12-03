#include "HUDManager.h"

void HUDManager::createHud(int healthMax, int health, int berries, int pokeballs)
{
	hud = std::make_shared<HUD>(healthMax, health, berries, pokeballs);
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

std::map<std::string, std::string> HUDManager::passFonts() const
{
	std::map<std::string, std::string> totalFonts;
	for (auto& t : hud->fonts) {
		totalFonts.try_emplace(t.first, t.second);
	}
	return totalFonts;
}

void HUDManager::updateHUD(int health, int berries, int pokeballs)
{
	hud->updateHUD(health, berries, pokeballs);
}