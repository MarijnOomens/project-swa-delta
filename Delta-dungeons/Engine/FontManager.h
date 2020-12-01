#pragma once

#include "FontAssetManager.h"
#include "RenderFacade.h"
#include <memory>
#include <string>
#include "Colour.h"

class FontManager
{
public:
	FontManager(std::shared_ptr<RenderFacade> rf, std::shared_ptr<FontAssetManager> fam);
	~FontManager() {}

	ENGINE_API void drawText(const std::string& text, const std::string& fontName, const Colour& colour, const Transform& transform, const int fontSize);
private:
	std::shared_ptr<FontAssetManager> fontAssetManager;
	std::shared_ptr<RenderFacade> renderFacade;
};