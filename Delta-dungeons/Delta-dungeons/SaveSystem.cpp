#include "SaveSystem.h"

void SaveSystem::save(GameStateObject state)
{
	std::cout << "saving game" << std::endl;
	rapidxml::xml_node<>* decl = saveDoc.allocate_node(rapidxml::node_type::node_declaration);
	decl->append_attribute(saveDoc.allocate_attribute("version", "1.0"));
	decl->append_attribute(saveDoc.allocate_attribute("encoding", "UTF-8"));
	saveDoc.append_node(decl);

	addNodeValue("CurrentLevel", state.currentLevel);

	std::string pokemonString = std::to_string(state.caughtPokemon);
	addNodeValue("CaughtPokemon", pokemonString);

	std::string highScoreString = std::to_string(state.highScore);
	addNodeValue("HighScore", highScoreString);

	std::string healthString = std::to_string(state.health);
	addNodeValue("Health", healthString);

	std::string pokeBallsString = std::to_string(state.pokeBalls);
	addNodeValue("Pokeballs", pokeBallsString);

	std::string berriesString = std::to_string(state.berries);
	addNodeValue("Berries", berriesString);

	std::string hasBoomerangString = std::to_string(state.hasBoomerang);
	addNodeValue("HasBoomerang", hasBoomerangString);

	std::string hasRunningShoesString = std::to_string(state.hasRunningShoes);
	addNodeValue("HasRunningShoes", hasRunningShoesString);

	std::string runningShoesActivatedString = std::to_string(state.runningShoesActivated);
	addNodeValue("RunningShoesActivated", runningShoesActivatedString);

	std::ofstream myfile("Assets/Data/save.xml", std::ios_base::trunc);
	if (!myfile.is_open())
	{
		std::cout << "File didn't open" << std::endl;
		return;
	}
	myfile << saveDoc;
	saveDoc.clear();
	myfile.close();
}

GameStateObject SaveSystem::load()
{
	GameStateObject state;

	rapidxml::file<> xmlFile("Assets/Data/save.xml");
	rapidxml::xml_document<> doc;

	doc.parse<0>(xmlFile.data());

	rapidxml::xml_node<>* node = doc.first_node("CurrentLevel");
	state.currentLevel = node->value();

	node = doc.first_node("CaughtPokemon");
	char* cp = node->value();
	state.caughtPokemon = (int)*cp - 48;

	node = doc.first_node("HighScore");
	char* hs = node->value();
	state.highScore = (int)*hs - 48;

	node = doc.first_node("Health");
	char* h = node->value();
	state.health = (int)*h - 48;

	node = doc.first_node("Pokeballs");
	char* pb = node->value();
	state.pokeBalls = (int)*pb - 48;

	node = doc.first_node("Berries");
	char* b = node->value();
	state.berries = (int)*b - 48;

	node = doc.first_node("HasBoomerang");
	char* boo = node->value();
	state.hasBoomerang = (int)*boo - 48;

	node = doc.first_node("HasRunningShoes");
	char* rs = node->value();
	state.hasRunningShoes = (int)*rs - 48;

	node = doc.first_node("RunningShoesActivated");
	char* rsa = node->value();
	state.runningShoesActivated = (int)*rsa - 48;

	return state;
}

void SaveSystem::addNodeValue(const char* name, const std::string& value)
{
	rapidxml::xml_node<>* newNode = saveDoc.allocate_node(rapidxml::node_element, name);
	newNode->value(value.c_str());
	saveDoc.append_node(newNode);
}
