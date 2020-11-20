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
	ENGINE_API ~TextureManager() {};

	ENGINE_API void loadTexture();
	//ENGINE_API void drawTexture(const std::string name, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimensions);
	ENGINE_API void drawText(const std::string &text,const std::string &fontName, const Colour &colour, const Transform& transform,const int fontSize);
	ENGINE_API void drawTexture(const std::string name, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimensions, 
		const int row, const int frames,const int speed,const bool animated,const bool flipped, const bool isScreen);
private:
	std::shared_ptr<AssetManager> assetManager;
	std::shared_ptr<RenderFacade> renderFacade;
};