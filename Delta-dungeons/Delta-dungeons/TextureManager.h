#pragma once
#include <string>
#include <memory>
#include "AssetManager.h"
#include "RenderFacade.h"

class TextureManager {
public:
	TextureManager();
	TextureManager(std::shared_ptr<RenderFacade> rf, std::shared_ptr<AssetManager> am);
	~TextureManager();

	void loadTexture();
	void drawTexture(const std::string name, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimensions);
private:
	std::shared_ptr<AssetManager> assetManager;
	std::shared_ptr<RenderFacade> renderFacade;
};
