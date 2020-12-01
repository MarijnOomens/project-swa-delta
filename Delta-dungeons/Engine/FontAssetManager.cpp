#include "FontAssetManager.h"

/// <summary>
/// This method adds a font with a given id and path to a map of fonts.
/// </summary>
/// <param name="id">ID/Name of font.</param>
/// <param name="path">Path of font.</param>
void FontAssetManager::addAsset(const std::string& id, const std::string& path)
{
	fontAssets.try_emplace(id, path);
}

/// <summary>
/// This method returns one font from the map, depending upon the given parameter.
/// </summary>
/// <param name="id">ID of font.</param>
/// <returns></returns>
std::string FontAssetManager::getAsset(const std::string& id)
{
	return fontAssets[id];
}