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