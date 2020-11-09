#include "TextureManager.h"

TextureManager::TextureManager() {}

/// <summary>
/// The TextureManager takes the created textures and gives them to the renderFacade to be rendered.
/// </summary>
/// <param name="rf">The Renderfacade.</param>
/// <param name="am">The AssetManager.</param>
TextureManager::TextureManager(std::shared_ptr<RenderFacade> rf, std::shared_ptr<AssetManager> am)
{
	assetManager = am;
	renderFacade = rf;
}

TextureManager::~TextureManager() {}

void TextureManager::loadTexture() {}

/// <summary>
/// gets the path of the texture and passes it onto the renderFacade.
/// </summary>
/// <param name="name">The name of the texture.</param>
/// <param name="transform">The Transform Rectangle</param>
/// <param name="coordinates">The x and y of the texture.</param>
/// <param name="sourceDimensions">The dimensions of the texture.</param>
/// <param name="row">The row of which animation, in case its animated.</param>
/// <param name="frames">The total animation frames in case its animated</param>
/// <param name="speed">The speed of the animation in case its animated</param>
/// <param name="animated">A boolean to represent if it is animated or not.</param>
/// <param name="flipped">A boolean to represent if it is flipped or not.</param>
void TextureManager::drawTexture(const std::string name, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimensions, int row, int frames, int speed, bool animated, bool flipped, bool isScreen)
{
	std::string texturePath = assetManager->getTexture(name);
	renderFacade->drawTexture(texturePath, transform, coordinates, sourceDimensions, row, frames, speed, animated, flipped,isScreen);

}

/// <summary>
/// gets the path of the text texture and passes it onto the renderFacade.
/// </summary>
/// <param name="fontName">The name of the texture.</param>
/// <param name="text">The string of text for the label.</param>
/// <param name="colour">The colour of the text.</param>
/// <param name="transform">The x and y of the text.</param>
/// <param name="fontSize">The size of the text.</param>
void TextureManager::drawText(std::string text, std::string fontName, Colour colour, const Transform& transform, int fontSize) 
{
	std::string fontPath = assetManager->getFont(fontName);
	renderFacade->drawText(fontPath, text, colour, transform, fontSize);
};
