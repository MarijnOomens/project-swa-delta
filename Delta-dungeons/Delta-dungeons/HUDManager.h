#pragma once
#include <string>
#include <map>
#include <memory>
#include "HUD.h"

class HUDManager
{
public:
	std::shared_ptr<HUD> hud;

	HUDManager() {};
	~HUDManager() {};

	void createHud(int healthMax, int health, int berries, int pokeballs);
	void addItem(const std::string& texturePath);
	std::map<std::string, std::string> passTextures() const;
	std::map<std::string, std::string> passFonts() const;
	void updateHUD(int health, int berries, int pokeballs);

};