#include "TextureAssetManager.h"

/// <summary>
/// This method adds a texture with a given id and path to a map of textures.
/// </summary>
/// <param name="id">ID/Name of texture.</param>
/// <param name="path">Path of texture.</param>
void TextureAssetManager::addAsset(const std::string& id, const std::string& path)
{
	if (!textureAssets.count(id))
	{
		textureAssets.try_emplace(id, path);
	}
}

/// <summary>
/// This method returns one texture from the map, depending upon the given parameter.
/// </summary>
/// <param name="id">ID of texture.</param>
/// <returns></returns>
std::string TextureAssetManager::getAsset(const std::string& id)
{
	return textureAssets[id];
}