#pragma once
#include <string>
#include <map>
#include "main.h"

class AssetManager {
public:

	AssetManager();
	~AssetManager(){};

	void addTexture(const std::string& id, const std::string& path);
	std::string getTexture(const std::string& id);
	void addFont(const std::string& id, const std::string& path);
	std::string getFont(const std::string& id);	
	void addAudio(const std::string& id, const std::string& path);
	std::string getAudio(const std::string& id);
private:
	std::map<const std::string, const std::string> textures;
	std::map<const std::string, const std::string> fonts;
	std::map<const std::string, const std::string> audio;
};