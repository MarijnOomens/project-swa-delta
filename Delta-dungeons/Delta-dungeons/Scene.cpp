#include "GraphicsComponent.h"
#include "Scene.h"
#include "XMLSceneParser.h"

/// <summary>
/// Scene is where a TileMap can be created.
/// </summary>

Scene::Scene() {}

Scene::Scene(const cbTileToPlayer f, void* p) : func(f), pointer(p) {}



Scene::Scene(int x, int y) : x(x), y(y) {};

Scene::~Scene() {}

void Scene::addGraphics()
{
	std::unique_ptr<XMLSceneParser> scene = std::make_unique<XMLSceneParser>();

	tileMap = scene.get()->loadScene("Assets\\collidermap.xml");

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
	texture.try_emplace("Level1", "Assets/Level1_terrain.png");
	return texture;
}

void Scene::checkCollision(int xPos, int yPos) {

	//for (int x = 0; x < tileMap.size(); x++)
	//{
	//	std::cout << tileMap.at(x).get()->transform.position.x << std::endl;
	//	std::cout << tileMap.at(x).get()->transform.position.x << std::endl;

	//	break;
	//}

	for (int x = 0; x < tileMap.size(); x++)
	{
		int tileX = tileMap.at(x).get()->transform.position.x;
		int tileY = tileMap.at(x).get()->transform.position.y;
		if (xPos == tileX && yPos == tileY)
		{
			std::cout << tileX << std::endl;
			std::cout << tileY << std::endl;

		std::cout << "we in checkcollision" << std::endl;
			func(pointer);
			break;
		}
	}
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

void Scene::updatePositions(int x, int y) {}