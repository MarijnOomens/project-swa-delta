#include "TextureManager.h"

TextureManager::TextureManager() {}

/// <summary>
/// The TextureManager takes the created textures and gives them to the renderFacade to be rendered.
/// </summary>
/// <param name="rf">The Renderfacade.</param>
/// <param name="am">The AssetManager.</param>
TextureManager::TextureManager(std::shared_ptr<RenderFacade> rf, std::shared_ptr<TextureAssetManager> tam)
{
	textureAssetManager = tam;
	renderFacade = rf;
}

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
	std::string texturePath = textureAssetManager->getAsset(name);
	renderFacade->drawTexture(texturePath, transform, coordinates, sourceDimensions, row, frames, speed, animated, flipped,isScreen);

}
