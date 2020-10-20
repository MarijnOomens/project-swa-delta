#pragma once
#include "IEquipment.h"

class Runningshoes: public IEquipment 
{
public: 
	Runningshoes();
	~Runningshoes();
	void use() override;
private:
	bool isActivated = false;

};