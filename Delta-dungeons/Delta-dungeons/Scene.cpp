#include "Scene.h"

/// <summary>
/// Scene is where a TileMap can be created.
/// </summary>

Scene::Scene(int x, int y) : x(x), y(y) {}

void Scene::addGraphics()
{
	XMLSceneParser sceneParser;

	tileMap = sceneParser.loadScene("Assets\\level1.xml");

	for (std::shared_ptr<Tile> t : tileMap)
	{
		std::string test = "Level1";
		t->addGraphicsComponent(test);
		components.emplace_back(std::move(t));
	}

	Colour color = { 0, 0, 0, 255 };
	fpsText = std::make_shared<TextComponent>("", "comic", color, 32);
	fpsText->transform.position = { 1200, 10 };
	components.emplace_back(fpsText);
}

/// <summary>
/// Creates a Vector of Tiles according to the ParserData it has been given.
/// </summary>
/// <param name="data">All the information needed to properly create a TileMap.</param>
/// <returns>If succeeded, it returns a TileMap that contains Tile objects.</returns>
std::vector<std::shared_ptr<Tile>> Scene::makeTiles(std::vector<std::shared_ptr<ParserData>> data)
{
	for (const std::shared_ptr<ParserData> tile : data)
	{
		int first = tile.get()->tileId[0] - 48;
		if (tile.get()->tileId[1]) {
			int second = tile.get()->tileId[1] - 48;
			tileMap.emplace_back(std::make_shared<Tile>(std::stoi(tile.get()->x), std::stoi(tile.get()->y), first, second));
		}
		else
		{
			tileMap.emplace_back(std::make_shared<Tile>(std::stoi(tile.get()->x), std::stoi(tile.get()->y), first));
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

void Scene::handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) 
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED)
	{
		switch (keyCode)
		{
		case KeyCodes::KEY_TAB:
			DebugUtilities::getInstance().toggleShowFPS();
			break;
		case KeyCodes::KEY_COMMA:
			DebugUtilities::getInstance().slowDownGame();
			break;
		case KeyCodes::KEY_POINT:
			DebugUtilities::getInstance().speedUpGame();
			break;
		case KeyCodes::KEY_SLASH:
			DebugUtilities::getInstance().resetSpeedGame();
			break;
		case KeyCodes::KEY_P:
			DebugUtilities::getInstance().pauseGame();
			break;
		default:
			break;
		}
	}
}

void Scene::update() 
{
	if (DebugUtilities::getInstance().isShowingFPS())
	{
		fpsString.str(std::to_string(DebugUtilities::getInstance().getFPS()));
		fpsText->changeText(fpsString.str());
	}
	else {
		fpsText->changeText("");
	}
}