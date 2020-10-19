#pragma once
#include <string>
#include <memory>
#include "AssetManager.h"
#include "RenderFacade.h"

class TextureManager {
public:
	TextureManager();
	TextureManager(std::shared_ptr<RenderFacade> rf);
	~TextureManager();

	void LoadTexture();
	void DrawTexture(std::string name);
private:
	std::unique_ptr<AssetManager> assetManager;
	std::shared_ptr<RenderFacade> renderFacade;
};
