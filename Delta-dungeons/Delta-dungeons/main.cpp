#define SDL_MAIN_HANDLED
#define _CRTDBG_MAP_ALLOC  
#include "AssetManager.h"
#include "BehaviourObject.h"
#include "EngineController.h"
#include "GraphicsComponent.h"
#include "Player.h"
#include "RenderFacade.h"
#include "TextureManager.h"
#include "Tile.h"
#include "XMLSceneParser.h"
#include <stdlib.h>  
#include <crtdbg.h>  
#include <memory>
#include <vector>
#include "GameManager.h"

int main(int argc, char* argv[])
{
	GameManager gameManager;
	_CrtDumpMemoryLeaks();
}
