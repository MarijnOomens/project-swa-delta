#include "Boomerang.h"
#include "Player.h"
#include "Runningshoes.h"
#include <windows.h>

/// <summary>
/// This class defines everything that has to do with the player character. Textures, input handling, health and caught Pok�mon
/// are all defined in the Player class. Interaction with the player's equipment is handled here too.
/// 
/// </summary>

const int animationSpeed = 120;


/// <summary>
/// Creates the running and boomerang equipments. And added to the equipment vector list.
/// Defines the movementspeed and the runactivated bool
/// Creates the graphicscomponent for the player sprite and saves the texturename and png location, width, height
/// </summary>
Player::Player(const cbCamera f, void* p): func(f), pointer(p)
{
	std::shared_ptr<Runningshoes> running = std::make_shared<Runningshoes>(staticEquipmentCallbackFunction, this);
	std::shared_ptr<Boomerang> boomerang = std::make_shared<Boomerang>();

	addEquipment(running);
	addEquipment(boomerang);

	baseMovementSpeed = 32;
	runActivated = false;

	this->transform.position.x = 512;
	this->transform.position.y = 384;
	x = this->transform.position.x;
	y = this->transform.position.y;


	this->textures.try_emplace("player_m", "Assets/player2_m_anims.png");
	this->textures.try_emplace("player_f", "Assets/player_f_anims.png");
	this->texture = "player_m";

	m_gc = std::make_shared<GraphicsComponent>();
	m_gc->setTexture("player_m");
	m_gc.get()->transform = this->transform;
	m_gc->imageDimensions = { 32, 32 };
	m_gc->transform.scale.multiply({ 4, 4 });
	m_gc->playAnimation(0, 3, animationSpeed, false);

	this->components.emplace_back(m_gc);
}

Player::~Player() 
{
}

/// <summary>
///	handleInput receives the keyboard input through keycodes and keyboardevents
/// </summary> 
/// <param name="Keycodes are enums and will be used to decide what action the user will make."></param>
/// <param name="keyboardEvent">KeyboardEvent will decide if handleKeyPressed or handleKeyReleased will be used</param>
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

/// <summary>
/// This method handles the logic when a keybutton has been pressed.
/// </summary>
/// <param name="keyCodes"></param>
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
	case KeyCodes::KEY_G:
		if (this->texture == "player_m") {
			m_gc->setTexture("player_f");
			this->texture = "npc";
		}
		else {
			m_gc->setTexture("player_m");
			this->texture = "player_m";
		}
		break;
	default:
		break;
	}
}

/// <summary>
/// This method handles the logic after the keybutton has been released.
/// </summary>
/// <param name="keyCodes"></param>
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

/// <summary>
/// This method moves the character up by changing the sprite animation and adjusting the Y coordinate
/// Running or walk animation will be used based on the runActivated boolean value.
/// </summary>
void Player::moveUp()
{
	y -= baseMovementSpeed;
	runActivated ? m_gc->playAnimation(7, 3, animationSpeed, false) :
		m_gc->playAnimation(2, 4, animationSpeed, false);
	func(pointer, x, y);
}

/// <summary>
/// This method moves the character down by changing the sprite animation and adjusting the Y coordinate
/// Running or walk animation will be used based on the runActivated boolean value.
/// </summary>
void Player::moveDown()
{
	y += baseMovementSpeed;
	runActivated ? m_gc->playAnimation(6, 3, animationSpeed, false) :
		m_gc->playAnimation(1, 4, animationSpeed, false);
	func(pointer, x, y);
}

/// <summary>
/// This method moves the character left by changing the sprite animation and adjusting the X coordinate
/// Running or walk animation will be used based on the runActivated boolean value.
/// </summary>
void Player::moveLeft()
{
	x -= baseMovementSpeed;
	runActivated ? m_gc->playAnimation(8, 3, animationSpeed, false) :
		m_gc->playAnimation(3, 4, animationSpeed, false);
	func(pointer, x, y);
}

/// <summary>
/// This method moves the character right by changing the sprite animation and adjusting the X coordinate
/// Running or walk animation will be used based on the runActivated boolean value.
/// </summary>
void Player::moveRight()
{
	x += baseMovementSpeed;
	runActivated ? m_gc->playAnimation(8, 3, animationSpeed, true) :
		m_gc->playAnimation(3, 4, animationSpeed, true);
	func(pointer, x, y);
}

/// <summary>
/// This method is a setter to add an equipment to the vector list called Equipment
/// </summary>
/// <param name="item">The equipment that will bed added</param>
void Player::addEquipment(std::shared_ptr<IEquipment> item)
{
	equipment.emplace_back(item);
}

/// <summary>
/// Callbackmethod to call the equipmentCallbackFunction.
/// </summary>
/// <param name="p">Is needed for the includes</param>
/// <param name="runningActivated">Boolean value for runActived Property</param>
void Player::staticEquipmentCallbackFunction(void* p, const bool runningActivated)
{
	((Player*)p)->equipmentCallbackFunction(runningActivated);

}

/// <summary>
/// This method changes the runActivated boolean and the baseMovementspeed based upon runningActivated
/// </summary>
/// <param name="runningActivated">This value will be used to set the runActivated property</param>
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

void Player::updatePositions(int x, int y){}