#include "AssetManager.h"

AssetManager::AssetManager() {};
AssetManager::~AssetManager() {};

void AssetManager::addTexture(std::string id, std::string path) {
	textures.emplace(id, path);
}

std::string AssetManager::getTexture(std::string id) {
	return textures[id];
}