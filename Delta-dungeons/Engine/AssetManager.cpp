#include "AssetManager.h"

AssetManager::AssetManager() {}
AssetManager::~AssetManager() {}

void AssetManager::addTexture(std::string id, std::string path)
{
	textures.try_emplace(id, path);
}

std::string AssetManager::getTexture(std::string id)
{
	return textures[id];
}

std::string AssetManager::getFont(std::string id) {}

void AssetManager::addFont(std::string id, std::string path, int fontSize) {}