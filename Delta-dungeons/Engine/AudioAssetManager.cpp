#include "AudioAssetManager.h"

/// <summary>
/// This method adds a Audio file with a given id and path to a map of fonts.
/// </summary>
/// <param name="id">ID/Name of audio.</param>
/// <param name="path">Path of audio.</param>
void AudioAssetManager::addAsset(const std::string& id, const std::string& path)
{
	audioAssets.try_emplace(id, path);
}

/// <summary>
/// This method returns one audio file from the map, depending upon the given parameter.
/// </summary>
/// <param name="id">ID of audio.</param>
/// <returns></returns>
std::string AudioAssetManager::getAsset(const std::string& id)
{
	return audioAssets[id];
}