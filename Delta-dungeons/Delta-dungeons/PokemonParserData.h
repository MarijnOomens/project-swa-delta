#pragma once

#include <string>

class PokemonParserData {

public:
	std::string name, encounterRate;

	PokemonParserData(const std::string& name, const std::string& encounterRate);
	~PokemonParserData() {}

};