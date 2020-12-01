#pragma once
#include "IAssetManager.h"

class TextureAssetManager : public IAssetManager
{
public:
	TextureAssetManager() {}
	~TextureAssetManager() {}

	void addAsset(const std::string& id, const std::string& path) override;
	std::string getAsset(const std::string& id) override;

private:
	std::map<const std::string, const std::string> textureAssets;
};