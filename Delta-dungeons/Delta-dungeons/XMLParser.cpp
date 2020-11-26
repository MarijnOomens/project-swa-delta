#include "XMLParser.h"

using namespace rapidxml;

/// <summary>
/// The XMLParser contains the logic to parse an .xml file into ParserData objects.
/// </summary>

/// <summary>
/// parseXML makes use of rapidxml. rapidxml is used to parse the given xml file path into ParserData objects. By selecting the right nodes, the nodes information can be saved in a new ParserData object.
/// </summary>
/// <param name="path">The location of the .xml file that will be parsed.</param>
/// <returns>A list of ParserData objects that can be used to create Tiles</returns>

std::vector<std::shared_ptr<ParserData>> XMLParser::parseXML(const std::string& path)
{
	std::vector<std::shared_ptr<ParserData>> parserDataList;
	rapidxml::file<> xmlFile(path.c_str());
	rapidxml::xml_document<> doc;

	doc.parse<0>(xmlFile.data());
	xml_node<>* node = doc.first_node("tilemap");

	for (xml_node<>* layer = node->first_node(); layer; layer = layer->next_sibling())
	{
		std::string layerName = layer->first_attribute("name")->value();

		if (layerName == "surface")
		{
			for (xml_node<>* tile = layer->first_node(); tile; tile = tile->next_sibling())
			{
				std::shared_ptr<ParserData> p = std::make_shared<ParserData>(tile->first_attribute("x")->value(), tile->first_attribute("y")->value(), tile->first_attribute("tile")->value());
				parserDataList.push_back(p);
			}
		}

		if (layerName == "collider")
		{
			for (xml_node<>* tile = layer->first_node(); tile; tile = tile->next_sibling())
			{
				std::string xVal = tile->first_attribute("x")->value();
				std::string yVal = tile->first_attribute("y")->value();
				std::string tileId = tile->first_attribute("tile")->value();

				if (tileId != "-1" && (tileId == "8" || tileId =="9"))
				{
					for (int x = 0; x < parserDataList.size(); x++)
					{
						if (xVal == parserDataList.at(x)->x && yVal == parserDataList.at(x)->y)
						{
							parserDataList.at(x)->isCollider = true;
							if (tileId == "9")
							{
								parserDataList.at(x)->isTrigger = true;
							}
							break;
						}
					}
				}
			}
		}
	}

	return parserDataList;
}

std::vector<std::shared_ptr<PokemonParserData>> XMLParser::loadPokemon(const std::string& path)
{
	std::vector<std::shared_ptr<PokemonParserData>> parserDataList;
	
	rapidxml::file<> xmlFile(path.c_str());
	rapidxml::xml_document<> doc;

	doc.parse<0>(xmlFile.data());
	xml_node<>* node = doc.first_node("Pokemons");

	for (xml_node<>* pokemon = node->first_node(); pokemon; pokemon = pokemon->next_sibling())
	{
		std::shared_ptr<PokemonParserData> p = std::make_shared<PokemonParserData>(pokemon->first_attribute("name")->value(), pokemon->first_attribute("encounterRate")->value());
		parserDataList.emplace_back(p);
	}

	return parserDataList;
}
/// <summary>
///  Gets the ParserData only for equipment.
/// </summary>
/// <returns> A list with parserdata for NPCs only.</returns>

std::vector<std::shared_ptr<ParserData>> XMLParser::getEquipmentDataList(const std::string& path)
{
	std::vector<std::shared_ptr<ParserData>> equipmentDataList;

	rapidxml::file<> xmlFile(path.c_str());
	rapidxml::xml_document<> doc;

	doc.parse<0>(xmlFile.data());
	xml_node<>* node = doc.first_node("tilemap");

	for (xml_node<>* layer = node->first_node(); layer; layer = layer->next_sibling())
	{
		std::string layerName = layer->first_attribute("name")->value();
		if (layerName == "collider")
		{
			for (xml_node<>* tile = layer->first_node(); tile; tile = tile->next_sibling())
			{
				std::string xVal = tile->first_attribute("x")->value();
				std::string yVal = tile->first_attribute("y")->value();
				std::string tileId = tile->first_attribute("tile")->value();

				//filters data for all equipment in the game.
				if (tileId == "3" || tileId == "4" || tileId == "5" || tileId == "6")
				{
					std::shared_ptr<ParserData> p = std::make_shared<ParserData>(tile->first_attribute("x")->value(), tile->first_attribute("y")->value(), tile->first_attribute("tile")->value());
					equipmentDataList.push_back(p);
				}
			}
		}
	}
	return equipmentDataList;
}

std::vector<std::shared_ptr<ParserData>> XMLParser::getNPCDataList(const std::string& path)
{
	std::vector<std::shared_ptr<ParserData>> npcDataList;

	rapidxml::file<> xmlFile(path.c_str());
	rapidxml::xml_document<> doc;

	doc.parse<0>(xmlFile.data());
	xml_node<>* node = doc.first_node("tilemap");

	for (xml_node<>* layer = node->first_node(); layer; layer = layer->next_sibling())
	{
		std::string layerName = layer->first_attribute("name")->value();
		if (layerName == "collider")
		{
			for (xml_node<>* tile = layer->first_node(); tile; tile = tile->next_sibling())
			{
				std::string xVal = tile->first_attribute("x")->value();
				std::string yVal = tile->first_attribute("y")->value();
				std::string tileId = tile->first_attribute("tile")->value();

				//filters data for all NPCs in the game.
				if (tileId == "1" || tileId == "7")
				{
					std::shared_ptr<ParserData> p = std::make_shared<ParserData>(tile->first_attribute("x")->value(), tile->first_attribute("y")->value(), tile->first_attribute("tile")->value());
					npcDataList.push_back(p);
				}
			}
		}
	}
	return npcDataList;
}