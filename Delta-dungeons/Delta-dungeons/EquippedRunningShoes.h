#pragma once
#include "IEquipment.h"

typedef void(*cbFunction) (void*, bool);

class EquippedRunningShoes : public IEquipment
{
public: 
	cbFunction func;
	void* pointer;
	bool isActivated = false;
	bool isCollider;

	EquippedRunningShoes();
	EquippedRunningShoes(const cbFunction f, void* p);
	~EquippedRunningShoes();
	void use() override;
};