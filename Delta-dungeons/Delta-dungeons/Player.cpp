#include "Boomerang.h"
#include "Player.h"
#include "Runningshoes.h"

Player::Player()
{
	std::shared_ptr<Runningshoes> running = std::make_shared<Runningshoes>(staticEquipmentCallbackFunction, this);
	std::shared_ptr<Boomerang> boomerang = std::make_shared<Boomerang>();

	addEquipment(running);
	addEquipment(boomerang);

	baseMovementSpeed = 32;

	this->textures.try_emplace("player", "Assets/player_anims.png");

	m_gc = std::make_shared<GraphicsComponent>();
	m_gc->setTexture("player");
	m_gc->imageDimensions = { 32, 32 };
	this->components.emplace_back(m_gc);
}

Player::~Player() {}

void Player::handleInput(const KeyCodes keyCodes, const KeyboardEvent keyboardEvent)
{
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
	//std::cout << "X: " << transform.position.x << ", Y: " << transform.position.y << std::endl;
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

void Player::damagePlayer(int damage) {}

void::Player::updateCaughtPokemon(int pokemonId) {}

void Player::callbackFunction() {}

void Player::connectCallback() {}

void Player::update() {}