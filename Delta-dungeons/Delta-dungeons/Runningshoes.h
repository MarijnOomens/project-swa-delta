#pragma once

#include "IEquipment.h"
typedef void(*cbFunction) (void*, bool);

class Runningshoes: public IEquipment 
{
public: 
	cbFunction func;
	void* pointer;
	bool isActivated = false;

	Runningshoes();
	Runningshoes(const cbFunction f, void* p);
	~Runningshoes();

	void use() override;

};