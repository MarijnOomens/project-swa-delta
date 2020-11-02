#include "Boomerang.h"
#include "Player.h"
#include "Runningshoes.h"
#include <windows.h>

/// <summary>
/// This class defines everything that has to do with the player character. Textures, input handling, health and caught Pokémon
/// are all defined in the Player class. Interaction with the player's equipment is handled here too.
/// 
/// </summary>

const int animationSpeed = 100; 

Player::Player(const cbCamera f, void* p): func(f), pointer(p)
{
	std::shared_ptr<Runningshoes> running = std::make_shared<Runningshoes>(staticEquipmentCallbackFunction, this);
	std::shared_ptr<Boomerang> boomerang = std::make_shared<Boomerang>();

	addEquipment(running);
	addEquipment(boomerang);

	baseMovementSpeed = 16;
	runActivated = false;

	this->transform.position.x = 500;
	this->transform.position.y = 300;
	x = this->transform.position.x;
	y = this->transform.position.y;


	this->textures.try_emplace("player", "Assets/player_anims.png");

	m_gc = std::make_shared<GraphicsComponent>();
	m_gc->setTexture("player");
	m_gc.get()->transform = this->transform;
	m_gc->imageDimensions = { 32, 32 };
	m_gc->transform.scale.multiply({ 2, 2 });
	m_gc->playAnimation(0, 3, animationSpeed, false);

	this->components.emplace_back(m_gc);
}

Player::~Player() 
{
}

void Player::handleInput(const KeyCodes keyCodes, const KeyboardEvent keyboardEvent)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED)
	{
		handleKeyPressed(keyCodes);
	}
	else if (keyboardEvent == KeyboardEvent::KEY_RELEASED)
	{
		handleKeyReleased(keyCodes);
	}
}

void Player::handleKeyPressed(const KeyCodes keyCodes)
{
	switch (keyCodes)
	{
	case KeyCodes::KEY_UP:
		moveUp();
		break;
	case KeyCodes::KEY_DOWN:
		moveDown();
		break;
	case KeyCodes::KEY_LEFT:
		moveLeft();
		break;
	case KeyCodes::KEY_RIGHT:
		moveRight();
		break;
	case KeyCodes::KEY_Q:
		for (auto& comp : equipment)
		{
			comp.get()->use();
		}
		break;
	case KeyCodes::KEY_E:
		std::cout << "Interaction button pressed..." << std::endl;
		break;
	default:
		break;
	}
}

void Player::handleKeyReleased(const KeyCodes keyCodes)
{
	switch (keyCodes)
	{
	case KeyCodes::KEY_UP:
		m_gc->playAnimation(4, 3, animationSpeed, false);
		break;
	case KeyCodes::KEY_DOWN:
		m_gc->playAnimation(0, 3, animationSpeed, false);
		break;
	case KeyCodes::KEY_LEFT:
		m_gc->playAnimation(5, 3, animationSpeed, false);
		break;
	case KeyCodes::KEY_RIGHT:
		m_gc->playAnimation(5, 3, animationSpeed, true);
		break;
	default:
		break;
	}
}

void Player::moveUp()
{
	y -= baseMovementSpeed;
	runActivated ? m_gc->playAnimation(7, 3, animationSpeed, false) :
		m_gc->playAnimation(2, 4, animationSpeed, false);
	func(pointer, x, y);
}

void Player::moveDown()
{
	y += baseMovementSpeed;
	runActivated ? m_gc->playAnimation(6, 3, animationSpeed, false) :
		m_gc->playAnimation(1, 4, animationSpeed, false);
	func(pointer, x, y);
}

void Player::moveLeft()
{
	x -= baseMovementSpeed;
	runActivated ? m_gc->playAnimation(8, 3, animationSpeed, false) :
		m_gc->playAnimation(3, 4, animationSpeed, false);
	func(pointer, x, y);
}

void Player::moveRight()
{
	x += baseMovementSpeed;
	runActivated ? m_gc->playAnimation(8, 3, animationSpeed, true) :
		m_gc->playAnimation(3, 4, animationSpeed, true);
	func(pointer, x, y);
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
	if (runningActivated) 
	{
		runActivated = true;
		baseMovementSpeed = 18;
		std::cout << " runningshoes enabled" << std::endl;
	}
	else 
	{
		runActivated = false;
		baseMovementSpeed = 12;
		std::cout << " runningshoes disabled" << std::endl;
	}
	//std::cout << runningActivated << " runningshoes" << std::endl;
}

void Player::damagePlayer(int damage) 
{
}

void::Player::updateCaughtPokemon(int pokemonId) 
{
}

void Player::callbackFunction() 
{
}

void Player::connectCallback() 
{
}

void Player::update() 
{
}

void Player::updatePositions(int x, int y){}