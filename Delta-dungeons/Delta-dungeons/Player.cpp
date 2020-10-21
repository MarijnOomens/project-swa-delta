#include "Player.h"
#include "Runningshoes.h"
#include "Boomerang.h"


Player::Player() {
	std::shared_ptr<Runningshoes> running = std::make_shared<Runningshoes>(staticEquipmentCallbackFunction, this);
	std::shared_ptr<Boomerang> boomerang = std::make_shared<Boomerang>();

	addEquipment(running);
	addEquipment(boomerang);
}
Player::~Player() {}

void Player::handleInput(const KeyCodes keyCodes, const KeyboardEvent keyboardEvent)
{
	std::cout << "This is a Player receiving input." << std::endl;


	if (keyCodes == KEY_UP) {
		this->transform.position.x + 1;
	}
	else if (keyCodes == KEY_DOWN) {
		this->transform.position.x - 1;
	}
	else if (keyCodes == KEY_Q) {
		for (auto& comp : equipment)
		{
			comp.get()->use();
		}
	}
	for (auto& comp : components)
	{
		comp->transform = this->transform;
	}
}

void Player::addEquipment(std::shared_ptr<IEquipment> item) 
{
	equipment.emplace_back(item);
}


void Player::staticEquipmentCallbackFunction(void* p, const bool runningActivated)
{
	((Player*)p)->equipmentCallbackFunction(runningActivated);

}

void Player::equipmentCallbackFunction(const bool runningActivated)
{
	std::cout << runningActivated << std::endl;
}



void Player::callbackFunction()
{
}


void Player::connectCallback() 
{
}
