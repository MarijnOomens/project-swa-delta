#pragma once

#include "AssetManager.h"
#include "RenderFacade.h"
#include <memory>
#include <string>
#include "Colour.h"

class TextureManager {
public:
	ENGINE_API TextureManager();
	ENGINE_API TextureManager(std::shared_ptr<RenderFacade> rf, std::shared_ptr<AssetManager> am);
	ENGINE_API ~TextureManager();

	ENGINE_API void loadTexture();
	ENGINE_API void drawTexture(const std::string name, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimensions);
	ENGINE_API void drawText(std::string text, std::string fontName, Colour colour, const Transform& transform);
private:
	std::shared_ptr<AssetManager> assetManager;
	std::shared_ptr<RenderFacade> renderFacade;
};