#include "Scene.h"

/// <summary>
/// Scene is where a TileMap can be created.
/// </summary>

Scene::Scene(int x, int y) : x(x), y(y) {}

void Scene::addGraphics()
{
	XMLSceneParser xmlSceneParser;

	tileMap = xmlSceneParser.loadScene("Assets/Maps/Level1/level1.xml");

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

std::map<std::string, std::string> Scene::passTextures() const
{
	std::map<std::string, std::string> texture;
	texture.try_emplace("Level1", "Assets/Maps/Level1/tileset-1.png");
	return texture;
}

void Scene::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)
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
	else
	{
		fpsText->changeText("");
	}
}

void Scene::interact() {}