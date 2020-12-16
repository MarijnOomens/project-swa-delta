#include "XMLFacade.h"

/// <summary>
/// XMLFacade is the facade between the XMLSceneParser and XMLParser.
/// </summary>

/// <summary>
/// Calls the XMLParser parse method.
/// </summary>
/// <param name="path">The location of the .xml file that will be parsed.</param>
/// <returns>A Vector of ParsedData object that can be used to create Tile objects.</returns>

std::vector<std::shared_ptr<ParserData>> XMLFacade::loadScene(const std::string& path)
{
	return parser.parseXML(path);
}

std::vector<std::shared_ptr<PokemonParserData>> XMLFacade::loadPokemon(const std::string& path)
{
	return parser.loadPokemon(path);
}

std::vector<std::shared_ptr<NPCParserData>>XMLFacade::loadNPC(const std::string& path)
{
	return parser.loadNPC(path);
}

/// <summary>
///  Gets the ParserData only for equipment.
/// </summary>
/// <returns> A list with parserdata for equipment only.</returns>
std::vector<std::shared_ptr<ParserData>> XMLFacade::getEquipmentDataList(const std::string& path)
{
	return parser.getEquipmentDataList(path);
}

std::vector<std::shared_ptr<ParserData>> XMLFacade::getNPCDataList(const std::string& path)
{
	return parser.getNPCDataList(path);
}

std::vector<std::shared_ptr<ParserData>> XMLFacade::getPuzzleData(const std::string& path)
{
	return parser.getPuzzleData(path);
}

std::shared_ptr<ParserData> XMLFacade::getPlayerPosition(const std::string& path)
{
	return parser.getPlayerPosition(path);
}