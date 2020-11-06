#include "ParserData.h"

/// <summary>
///  ParserData holds information which can be used to create a Tile object with.
/// </summary>

ParserData::ParserData() {}

/// <summary>
/// Creates a ParserData object.
/// </summary>
/// <param name="x">X position of a Tile</param>
/// <param name="y">Y position of a Tile</param>
/// <param name="tileId">TileId of a Tile within so the correct part of the asset can be selected</param>

ParserData::ParserData(const std::string x, const std::string y, const std::string tileId) : x(x), y(y), tileId(tileId) {}

ParserData::~ParserData() {}