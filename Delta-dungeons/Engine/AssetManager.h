#pragma once

#include <string>
#include <map>

class AssetManager {
public:
	AssetManager();
	~AssetManager();

	void addTexture(std::string id, std::string path);
	std::string getTexture(std::string id);

	void addFont(std::string id, std::string path, int fontSize);
	std::string getFont(std::string id);

private:
	std::map<std::string, std::string> textures;
	std::map<std::string, std::string> fonts;
};