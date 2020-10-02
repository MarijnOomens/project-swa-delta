#pragma once
#include <string>

class ColliderComponent {
	std::string tag;
	void CallbackFunction();
public:
	ColliderComponent();
	~ColliderComponent();
};