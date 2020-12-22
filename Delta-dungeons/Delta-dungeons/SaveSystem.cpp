#include "SaveSystem.h"

void SaveSystem::save(const std::string& currentLevel, int caughtPokemon, int health, int pokeBalls, int berries, bool hasBoomerang, bool hasRunningShoes, bool runningShoesActivated)
{
	std::cout << "saving game" << std::endl;
	rapidxml::xml_node<>* decl = saveDoc.allocate_node(rapidxml::node_type::node_declaration);
	decl->append_attribute(saveDoc.allocate_attribute("version", "1.0"));
	decl->append_attribute(saveDoc.allocate_attribute("encoding", "UTF-8"));
	saveDoc.append_node(decl);

	addNodeValue("CurrentLevel", currentLevel);

	std::string pokemonString = std::to_string(caughtPokemon);
	addNodeValue("CaughtPokemon", pokemonString);

	std::string healthString = std::to_string(health);
	addNodeValue("Health", healthString);

	std::string pokeBallsString = std::to_string(pokeBalls);
	addNodeValue("Pokeballs", pokeBallsString);

	std::string berriesString = std::to_string(berries);
	addNodeValue("Berries", berriesString);

	std::string hasBoomerangString = std::to_string(hasBoomerang);
	addNodeValue("HasBoomerang", hasBoomerangString);

	std::string hasRunningShoesString = std::to_string(hasRunningShoes);
	addNodeValue("HasRunningShoes", hasRunningShoesString);

	std::string runningShoesActivatedString = std::to_string(runningShoesActivated);
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

void SaveSystem::addNodeValue(const char* name, const std::string& value)
{
	rapidxml::xml_node<>* newNode = saveDoc.allocate_node(rapidxml::node_element, name);
	newNode->value(value.c_str());
	saveDoc.append_node(newNode);
}
