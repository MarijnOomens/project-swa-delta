#include "GraphicsComponent.h"
#include "Scene.h"
#include "XMLSceneParser.h"

/// <summary>
/// Scene is where a TileMap can be created.
/// </summary>

Scene::Scene() {}

Scene::Scene(int x, int y) : x(x), y(y) {};

Scene::~Scene() {}

void Scene::addGraphics()
{
	std::unique_ptr<XMLSceneParser> scene = std::make_unique<XMLSceneParser>();

	tileMap = scene.get()->loadScene("Assets\\level1.xml");

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
			tileMap.push_back(std::make_shared<Tile>(std::stoi(tile.get()->x), std::stoi(tile.get()->y), first, second));
		}
		else
		{
			tileMap.push_back(std::make_shared<Tile>(std::stoi(tile.get()->x), std::stoi(tile.get()->y), first));
		}
	}
	return tileMap;
}

std::map<std::string, std::string> Scene::passTextures() const
{
	std::map<std::string, std::string> texture;
	texture.try_emplace("Level1", "Assets/tileset-1.png");
	return texture;
}

void Scene::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) {}

void Scene::connectCallback() {}

void Scene::callbackFunction() {}

void Scene::update() 
{
	/*for (auto& t : tileMap)
	{
		t.get()->transform.position.x += playerpos.x * 
	}*/


}

void Scene::updatePositions(int x, int y){}