#pragma once

#include "IEquipment.h"

typedef void(*cbFunction) (void*, bool);

class Runningshoes : public IEquipment 
{
public: 
	Runningshoes(const cbFunction f, void* p, std::string& t);
	~Runningshoes() {}

	void use() override;

private:
	cbFunction func;
	void* pointer;
	bool isActivated = false;
};