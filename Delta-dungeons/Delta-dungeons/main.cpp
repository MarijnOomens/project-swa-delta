#define SDL_MAIN_HANDLED
#define _CRTDBG_MAP_ALLOC  
#include "EngineController.h"
#include <stdlib.h>  
#include <crtdbg.h>  
#include <memory>
#include <vector>
#include "XMLSceneParser.h"
#include "AssetManager.h"
#include "TextureManager.h"
#include "Player.h"
#include "BehaviourObject.h"
#include "RenderFacade.h"
#include "Tile.h"
#include "GraphicsComponent.h"

int main(int argc, char* argv[])
{
	std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects;
	std::shared_ptr<RenderFacade>renderFacade = std::make_shared<RenderFacade>();
	std::shared_ptr<AssetManager>assetManager = std::make_shared<AssetManager>();
	std::shared_ptr<TextureManager>textureManager = std::make_shared<TextureManager>(renderFacade, assetManager);
	// TILEMAP
	std::unique_ptr<XMLSceneParser> scene = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<Tile>> tiles = scene.get()->loadScene("Assets\\collisionmap.xml");
	assetManager->addTexture("Level1", "Assets\\Level1_terrain.png");
	for (std::shared_ptr<Tile> t : tiles)
	{
		std::shared_ptr<GraphicsComponent> gc = std::make_shared<GraphicsComponent>();
		gc.get()->addTextureManager(textureManager);
		t->addGraphicsComponent(gc, "Level1");
		behaviourObjects.emplace_back(gc);
		behaviourObjects.emplace_back(t);
	}

	// PLAYER
	assetManager->addTexture("player_anims", "Assets\\player_anims.png");
	std::shared_ptr<GraphicsComponent> gcPlayer = std::make_shared<GraphicsComponent>();
	gcPlayer.get()->addTextureManager(textureManager);
	behaviourObjects.emplace_back(gcPlayer);
	std::shared_ptr<Player> player = std::make_shared<Player>("player_anims", gcPlayer);
	behaviourObjects.emplace_back(player);

    std::unique_ptr<EngineController> engineController = std::make_unique<EngineController>(behaviourObjects,renderFacade,assetManager,textureManager);
    _CrtDumpMemoryLeaks();
      return 0;
}
