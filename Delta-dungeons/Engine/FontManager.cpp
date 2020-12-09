#include "FontManager.h"

FontManager::FontManager(std::shared_ptr<RenderFacade> rf, std::shared_ptr<FontAssetManager> fam) : renderFacade(rf), fontAssetManager(fam) {}

/// <summary>
/// gets the path of the text texture and passes it onto the renderFacade.
/// </summary>
/// <param name="fontName">The name of the texture.</param>
/// <param name="text">The string of text for the label.</param>
/// <param name="colour">The colour of the text.</param>
/// <param name="transform">The x and y of the text.</param>
/// <param name="fontSize">The size of the text.</param>
void FontManager::drawText(const std::string& text, const std::string& fontName, const Colour& colour, const Transform& transform, const int fontSize)
{
	std::string fontPath = fontAssetManager->getAsset(fontName);
	renderFacade->drawTexture(fontPath, text, colour, transform, fontSize);
};