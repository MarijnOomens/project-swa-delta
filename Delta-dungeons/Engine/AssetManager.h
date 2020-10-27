#pragma once

#include <string>
#include <map>
#include "main.h"

class AssetManager {
public:

	ENGINE_API AssetManager();
	ENGINE_API ~AssetManager();

	ENGINE_API void addTexture(std::string id, std::string path);
	std::string getTexture(std::string id);

	std::string getFont(std::string id);
	void addFont(std::string id, std::string path, int fontSize);
private:
	std::map<std::string, std::string> textures;
	std::map<std::string, std::string> fonts;
};