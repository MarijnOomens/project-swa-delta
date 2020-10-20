#include "Player.h"

//Player::Player() {}

void Player::handleInput(const KeyCodes keyCodes, const KeyboardEvent keyboardEvent)
{
	std::cout << "This is a Player receiving input." << std::endl;


	if (keyCodes == KEY_UP) {
		this->transform.position.x + 1;
	}
	else if (keyCodes == KEY_DOWN) {
		this->transform.position.x - 1;
	}
	for (auto& comp : components)
	{
		comp->transform = this->transform;
	}
}


void Player::connectCallback() {}
void Player::callbackFunction() {}