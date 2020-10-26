#include "Player.h"
#include "Runningshoes.h"
#include "Boomerang.h"

Player::Player() {}

Player::Player(std::string texture, std::shared_ptr<GraphicsComponent> gc) {
	std::shared_ptr<Runningshoes> running = std::make_shared<Runningshoes>(staticEquipmentCallbackFunction, this);
	std::shared_ptr<Boomerang> boomerang = std::make_shared<Boomerang>();

	addEquipment(running);
	addEquipment(boomerang);

	baseMovementSpeed = 32;

	m_gc = gc;
	m_gc->setTexture(texture);
}

Player::~Player() {}

void Player::handleInput(const KeyCodes keyCodes, const KeyboardEvent keyboardEvent)
{
	std::cout << "This is a Player receiving input." << std::endl;

	if (keyCodes == KEY_UP) {

		this->transform.position.y -= baseMovementSpeed;
		m_gc->transform.position.y = this->transform.position.y;
	}
	else if (keyCodes == KEY_DOWN) {
		this->transform.position.y += baseMovementSpeed;
		m_gc->transform.position.y = this->transform.position.y;
	}
	else if (keyCodes == KEY_RIGHT)
	{
		this->transform.position.x += baseMovementSpeed;
		m_gc->transform.position.x = this->transform.position.x;
	}
	else if (keyCodes == KEY_LEFT)
	{
		this->transform.position.x -= baseMovementSpeed;
		m_gc->transform.position.x = this->transform.position.x;
	}
	else if (keyCodes == KEY_Q) {
		for (auto& comp : equipment)
		{
			comp.get()->use();
		}
	}
	for (auto& comp : components)
	{
		comp->transform.position = this->transform.position;
	}
	std::cout << "X: " << transform.position.x << ", Y: " << transform.position.y << std::endl;

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
	if (runningActivated) {
		baseMovementSpeed = 64;
		std::cout << " runningshoes activated" << std::endl;

	}
	else {
		baseMovementSpeed = 32;
		std::cout << " runningshoes deactivate" << std::endl;

	}
	std::cout << runningActivated << " runningshoes" << std::endl;
}

void Player::callbackFunction() {}


void Player::connectCallback() {}

void Player::update() {}
