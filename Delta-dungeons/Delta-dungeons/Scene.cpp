#include "Scene.h"

/// <summary>
/// Scene is where a TileMap can be created.
/// </summary>

Scene::Scene(const cbTileToPlayer f, void* p) : func(f), pointer(p) {}

Scene::Scene(int x, int y) : x(x), y(y) {}

void Scene::addGraphics()
{
	XMLSceneParser xmlSceneParser;

	tileMap = xmlSceneParser.loadScene("Assets/maps/level1.xml");

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
	texture.try_emplace("Level1", "Assets/Maps/tileset-1.png");
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

void Scene::checkCollision(int xPos, int yPos)
{
	for (int x = 0; x < tileMap.size(); x++)
	{
		int isCollider = tileMap.at(x).get()->components.size();

		if (isCollider > 1)
		{
			int tileX = tileMap.at(x).get()->components.at(1).get()->transform.position.x;
			int tileY = tileMap.at(x).get()->components.at(1).get()->transform.position.y;

			if (xPos == tileX && yPos == tileY)
			{
				// Logs for collision debug purposes
				//std::cout << "Tile and player collision prediction." << std::endl;
				//std::cout << "Tries moving to x: " << xPos << std::endl;
				//std::cout << "Tries moving to y: " << yPos << std::endl;
				//std::cout << "Target tile x: " << tileX << std::endl;
				//std::cout << "Target tile y: " << tileY << std::endl;
				//std::cout << "Tile isCollider " << isCollider << std::endl;
				//std::cout << "-------------------------------------" << std::endl;

				if (isCollider > 1) {
					//std::cout << "This is a Tile with Collision" << std::endl;
					func(pointer);
					break;
				}
			}
		}
	}
}