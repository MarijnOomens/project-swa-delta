#pragma once

#include <string>

class PokemonParserData {

public:
	std::string name, encounterRate, attackTime;

	PokemonParserData(const std::string& name, const std::string& encounterRate, const std::string& attackTime);
	~PokemonParserData() {}

};