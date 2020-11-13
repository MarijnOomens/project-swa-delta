#pragma once

#include <string>

class ColliderComponent {
public:
	std::string tag;

	ColliderComponent() {};
	~ColliderComponent() {};

	void CallbackFunction();
};