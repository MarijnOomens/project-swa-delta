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
	~HUDManager() {}

	void createHud();
	void addItem(const std::string& texturePath);
	std::map<std::string, std::string> passTextures() const;

};