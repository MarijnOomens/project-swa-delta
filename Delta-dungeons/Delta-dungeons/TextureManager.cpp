#include "TextureManager.h"

TextureManager::TextureManager(std::shared_ptr<RenderFacade> rf) {
	assetManager = std::make_unique<AssetManager>();
	renderFacade = rf;
};
TextureManager::~TextureManager() {};

void TextureManager::LoadTexture() {};
void TextureManager::DrawTexture(std::string name) {

	//assetManager->addTexture("button_play", "assets/button_play.png");
	//std::string path = assetManager->getTexture(name);
	Vector2D rect(32, 64);
	Vector2D dest(100, 100);
	renderFacade->drawTexture("assets/button_play.png", rect, dest);
	
};
