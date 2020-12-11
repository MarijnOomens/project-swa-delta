#pragma once
#include <string>
#include <map>
#include "main.h"

class IAssetManager {
public:

	virtual void addAsset(const std::string& id, const std::string& path) = 0;
	virtual std::string getAsset(const std::string& id) = 0;
};