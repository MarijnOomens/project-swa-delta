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