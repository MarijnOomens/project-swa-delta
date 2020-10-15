#pragma once
#include <string>
#include <memory>
#include "AssetManager.h"
#include "RenderFacade.h"

class TextureManager {
public:
	TextureManager();
	~TextureManager();

	void LoadTexture();
	void DrawTexture(std::string name);
private:
	std::unique_ptr<AssetManager> assetManager;
	std::unique_ptr<RenderFacade> renderFacade;
};
