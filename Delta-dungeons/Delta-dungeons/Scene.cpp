#include "GraphicsComponent.h"
#include "Scene.h"
#include "XMLSceneParser.h"

/// <summary>
/// Scene is where a TileMap can be created.
/// </summary>

Scene::Scene() {}

Scene::Scene(const cbTileToPlayer f, void* p) : func(f), pointer(p) {}

Scene::Scene(int x, int y) : x(x), y(y) {}

Scene::~Scene() {}

void Scene::addGraphics()
{
	std::unique_ptr<XMLSceneParser> xmlSceneParser = std::make_unique<XMLSceneParser>();

	tileMap = xmlSceneParser.get()->loadScene("Assets/Level/level1.xml");

	for (std::shared_ptr<Tile> t : tileMap)
	{
		t->addGraphicsComponent("Level1");
		components.emplace_back(t);
	}
}

/// <summary>
/// Creates a Vector of Tiles according to the ParserData it has been given.
/// </summary>
/// <param name="data">All the information needed to properly create a TileMap.</param>
/// <returns>If succeeded, it returns a TileMap that contains Tile objects.</returns>

std::vector<std::shared_ptr<Tile>> Scene::makeTiles(std::vector<std::shared_ptr<ParserData>> data)
{
	for (std::shared_ptr<ParserData> tile : data)
	{
		int first = tile.get()->tileId[0] - 48;
		if (tile.get()->tileId[1]) {
			int second = tile.get()->tileId[1] - 48;
			tileMap.push_back(std::make_shared<Tile>(std::stoi(tile.get()->x), std::stoi(tile.get()->y), first, second, tile.get()->isCollider));
		}
		else
		{
			tileMap.push_back(std::make_shared<Tile>(std::stoi(tile.get()->x), std::stoi(tile.get()->y), first, tile.get()->isCollider));
		}

	}
	return tileMap;
}

std::map<std::string, std::string> Scene::passTextures() const
{
	std::map<std::string, std::string> texture;
	texture.try_emplace("Level1", "Assets/Tileset/tileset-1.png");
	return texture;
}

void Scene::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos) {}

void Scene::update() {}

void Scene::checkCollision(int xPos, int yPos)
{
	for (int x = 0; x < tileMap.size(); x++)
	{
		int tileX = tileMap.at(x).get()->originX;
		int tileY = tileMap.at(x).get()->originY;
		bool isCollider = tileMap.at(x).get()->isCollider;

		if (xPos == tileX && yPos == tileY)
		{
			// Logs for collision debug purposes
			std::cout << "Tile and player collision prediction." << std::endl;
			std::cout << "Tries moving to x: " << xPos << std::endl;
			std::cout << "Tries moving to y: " << yPos << std::endl;
			std::cout << "Target tile x: " << tileX << std::endl;
			std::cout << "Target tile y: " << tileY << std::endl;
			std::cout << "Tile isCollider " << isCollider << std::endl;
			std::cout << "-------------------------------------" << std::endl;
			if (isCollider) {
				std::cout << "This is a Tile with Collision" << std::endl;
				func(pointer);
				break;
			}
		}
	}
}