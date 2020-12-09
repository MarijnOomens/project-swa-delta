#pragma once

#include "TextureAssetManager.h"
#include "RenderFacade.h"
#include <memory>
#include <string>

class TextureManager {
public:
	ENGINE_API TextureManager();
	ENGINE_API TextureManager(std::shared_ptr<RenderFacade> rf, std::shared_ptr<TextureAssetManager> am);
	ENGINE_API ~TextureManager() {};

	ENGINE_API void drawTexture(const std::string& name, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimensions,
		const int row, const int frames, const int speed, const bool animated, const bool flipped, const bool isScreen);
private:
	std::shared_ptr<TextureAssetManager> textureAssetManager;
	std::shared_ptr<RenderFacade> renderFacade;
};