#include "GameState.h"

GameState GameState::gameState;

GameState& GameState::getInstance()
{
	return gameState;
}

void GameState::reset()
{
	currentLevel = "Level1";
	caughtPokemon = 0;
	health = 5;
	pokeBalls = 20;
	berries = 0;
	hasBoomerang = false;
	hasRunningShoes = true;
	runningShoesActivated = false;
}

void GameState::addCaughPokemon(int amount)
{
	this->caughtPokemon += amount;
	if (caughtPokemon > highScore)
	{
		highScore = caughtPokemon;
	}
}

int GameState::getCaughtPokemon()
{
	return caughtPokemon;
}

int GameState::getHighScore()
{
	return highScore;
}

void GameState::Save()
{
	std::cout << "saving game" << std::endl;
	rapidxml::xml_node<>* decl = saveDoc.allocate_node(rapidxml::node_type::node_declaration);
	decl->append_attribute(saveDoc.allocate_attribute("version", "1.0"));
	decl->append_attribute(saveDoc.allocate_attribute("encoding", "UTF-8"));
	saveDoc.append_node(decl);

	rapidxml::xml_node<>* files = saveDoc.allocate_node(rapidxml::node_element, "Files");
	saveDoc.append_node(files);
	rapidxml::xml_attribute<>* attr = saveDoc.allocate_attribute("dummy", "google.com");
	files->append_attribute(attr);


	std::ofstream myfile;
	myfile.open("example.xml");
	myfile << saveDoc;
}
