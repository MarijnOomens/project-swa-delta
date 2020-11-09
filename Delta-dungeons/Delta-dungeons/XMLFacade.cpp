#include "XMLFacade.h"

/// <summary>
/// XMLFacade is the facade between the XMLSceneParser and XMLParser.
/// </summary>

XMLFacade::XMLFacade()
{
	parser = std::make_unique<XMLParser>();
}

XMLFacade::~XMLFacade() {}

/// <summary>
/// Calls the XMLParser parse method.
/// </summary>
/// <param name="path">The location of the .xml file that will be parsed.</param>
/// <returns>A Vector of ParsedData object that can be used to create Tile objects.</returns>

std::vector<std::shared_ptr<ParserData>> XMLFacade::loadScene(const char* path)
{
	return parser->parseXML(path);
}

/// <summary>
///  Gets the ParserData only for equipment.
/// </summary>
/// <returns> A list with parserdata for equipment only.</returns>

std::vector<std::shared_ptr<ParserData>> XMLFacade::getEquipmentDataList(const char* path)
{
	return parser->getEquipmentDataList(path);
}