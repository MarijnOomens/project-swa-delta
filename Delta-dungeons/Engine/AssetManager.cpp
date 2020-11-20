#include "AssetManager.h"

/// <summary>
/// This class is a manager for all assets. Textures, fonts and sounds are added to a map here.
/// </summary>

AssetManager::AssetManager() {}

/// <summary>
/// This method adds a texture with a given id and path to a map of textures.
/// </summary>
/// <param name="id">ID/Name of texture.</param>
/// <param name="path">Path of texture.</param>
void AssetManager::addTexture(const std::string& id, const std::string& path)
{
	textures.try_emplace(id, path);
}

/// <summary>
/// This method returns one texture from the map, depending upon the given parameter.
/// </summary>
/// <param name="id">ID of texture.</param>
/// <returns></returns>
std::string AssetManager::getTexture(const std::string& id)
{
	return textures[id];
}

/// <summary>
/// This method adds a font with a given id and path to a map of fonts.
/// </summary>
/// <param name="id">ID/Name of font.</param>
/// <param name="path">Path of font.</param>
void AssetManager::addFont(const std::string& id, const std::string& path) 
{
	fonts.try_emplace(id, path);
}

/// <summary>
/// This method returns one font from the map, depending upon the given parameter.
/// </summary>
/// <param name="id">ID of font.</param>
/// <returns></returns>
std::string AssetManager::getFont(const std::string& id)
{
	return fonts[id];
}