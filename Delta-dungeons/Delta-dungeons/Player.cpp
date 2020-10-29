#include "Boomerang.h"
#include "Player.h"
#include "Runningshoes.h"

/// <summary>
/// This class defines everything that has to do with the player character. Textures, input handling, health and caught Pokémon
/// are all defined in the Player class. Interaction with the player's equipment is handled here too.
/// 
/// </summary>

Player::Player()
{
	std::shared_ptr<Runningshoes> running = std::make_shared<Runningshoes>(staticEquipmentCallbackFunction, this);
	std::shared_ptr<Boomerang> boomerang = std::make_shared<Boomerang>();

	addEquipment(running);
	addEquipment(boomerang);

	baseMovementSpeed = 32;
	runActivated = false;

	this->textures.try_emplace("player", "Assets/player_anims.png");

	m_gc = std::make_shared<GraphicsComponent>();
	m_gc->setTexture("player");
	m_gc->imageDimensions = { 32, 32 };
	m_gc->transform.scale.multiply({ 3, 3 });
	m_gc->playAnimation(AnimTypes::IDLE_FRONT, AnimFlip::NO_FLIP);

	this->components.emplace_back(m_gc);
}

Player::~Player() 
{
}

void Player::handleInput(const KeyCodes keyCodes, const KeyboardEvent keyboardEvent)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED)
	{
		if (keyCodes == KeyCodes::KEY_UP)
		{
			this->transform.position.y -= baseMovementSpeed;
			runActivated ? m_gc->playAnimation(AnimTypes::RUN_BACK, AnimFlip::NO_FLIP) : m_gc->playAnimation(AnimTypes::WALK_BACK, AnimFlip::NO_FLIP);
		}
		else if (keyCodes == KeyCodes::KEY_DOWN)
		{
			this->transform.position.y += baseMovementSpeed;
			runActivated ? m_gc->playAnimation(AnimTypes::RUN_FRONT, AnimFlip::NO_FLIP) : m_gc->playAnimation(AnimTypes::WALK_FRONT, AnimFlip::NO_FLIP);
		}
		else if (keyCodes == KeyCodes::KEY_RIGHT)
		{
			this->transform.position.x += baseMovementSpeed;
			runActivated ? m_gc->playAnimation(AnimTypes::RUN_SIDE, AnimFlip::FLIP) : m_gc->playAnimation(AnimTypes::WALK_SIDE, AnimFlip::FLIP);
		}
		else if (keyCodes == KeyCodes::KEY_LEFT)
		{
			this->transform.position.x -= baseMovementSpeed;
			runActivated ? m_gc->playAnimation(AnimTypes::RUN_SIDE, AnimFlip::NO_FLIP) : m_gc->playAnimation(AnimTypes::WALK_SIDE, AnimFlip::NO_FLIP);
		}
		else if (keyCodes == KeyCodes::KEY_Q)
		{
			for (auto& comp : equipment)
			{
				comp.get()->use();
			}
		}
		else if (keyCodes == KeyCodes::KEY_E)
		{
			std::cout << "Interaction button pressed..." << std::endl;
		}
		//std::cout << "X: " << transform.position.x << ", Y: " << transform.position.y << std::endl;
	}
	else if (keyboardEvent == KeyboardEvent::KEY_RELEASED)
	{
		if (keyCodes == KeyCodes::KEY_UP)
		{
			m_gc->playAnimation(AnimTypes::IDLE_BACK, AnimFlip::NO_FLIP);
		}
		else if (keyCodes == KeyCodes::KEY_DOWN) {
			m_gc->playAnimation(AnimTypes::IDLE_FRONT, AnimFlip::NO_FLIP);
		}
		else if (keyCodes == KeyCodes::KEY_RIGHT)
		{
			m_gc->playAnimation(AnimTypes::IDLE_SIDE, AnimFlip::FLIP);
		}
		else if (keyCodes == KeyCodes::KEY_LEFT)
		{
			m_gc->playAnimation(AnimTypes::IDLE_SIDE, AnimFlip::NO_FLIP);
		}
	}

	for (auto& comp : components)
	{
		comp->transform.position = this->transform.position;
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
	if (runningActivated) 
	{
		runActivated = true;
		baseMovementSpeed = 64;
		std::cout << " runningshoes enabled" << std::endl;
	}
	else 
	{
		runActivated = false;
		baseMovementSpeed = 32;
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