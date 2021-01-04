#include "PokemonParserData.h"

/// <summary>
///  ParserData holds information which can be used to create a Tile object with.
/// </summary>

/// <summary>
/// Creates a ParserData object.
/// </summary>
/// <param name="x">X position of a Tile</param>
/// <param name="y">Y position of a Tile</param>
/// <param name="tileId">TileId of a Tile within so the correct part of the asset can be selected</param>

PokemonParserData::PokemonParserData(const std::string& name, const std::string& encounterRate, const std::string& attackTime) : name(name), encounterRate(encounterRate), attackTime(attackTime) {}