#include "Boomerang.h"
#include "Player.h"
#include "RunningShoes.h"
#include <windows.h>

/// <summary>
/// This class defines everything that has to do with the player character. Textures, input handling, health and caught Pok�mon
/// are all defined in the Player class. Interaction with the player's equipment is handled here too.
/// </summary>

const int animationSpeed = 120;

/// <summary>
/// Creates the running and boomerang equipments. And added to the equipment vector list.
/// Defines the movementspeed and the runactivated bool
/// Creates the graphicscomponent for the player sprite and saves the texturename and png location, width, height
/// </summary>
Player::Player(const cbCamera f, const cbTile cbTile, const cbInteractWithEquipmentManager eqMF, void* p) : func(f), tileFunc(cbTile), eqManagerFunc(eqMF), pointer(p)
{
	std::shared_ptr<RunningShoes> running = std::make_shared<RunningShoes>(staticEquipmentCallbackFunction, this);
	std::shared_ptr<Boomerang> boomerang = std::make_shared<Boomerang>();

	addEquipment(running);
	addEquipment(boomerang);

	baseMovementSpeed = 128;
	runActivated = false;
	tileCollision = false;

	this->transform.position.x = 1024;
	this->transform.position.y = 768;
	x = this->transform.position.x;
	y = this->transform.position.y;


	this->textures.try_emplace("player_m", "Assets/player2_m_anims.png");
	this->textures.try_emplace("player_f", "Assets/player_f_anims.png");
	this->texture = "player_m";

	m_gc = std::make_shared<GraphicsComponent>();
	m_gc->setTexture("player_m");
	m_gc->isScreen = false;
	m_gc.get()->transform = this->transform;
	m_gc->imageDimensions = { 32, 32 };
	m_gc->transform.scale.multiply({ 4, 4 });
	m_gc->playAnimation(0, 3, animationSpeed, false);

	this->components.emplace_back(m_gc);
	currentDirection = KeyCodes::KEY_DOWN;
}

Player::~Player() {}

/// <summary>
///	handleInput receives the keyboard input through keycodes and keyboardevents
/// </summary> 
/// <param name="Keycodes are enums and will be used to decide what action the user will make."></param>
/// <param name="keyboardEvent">KeyboardEvent will decide if handleKeyPressed or handleKeyReleased will be used</param>
void Player::handleInput(const KeyCodes keyCodes, const KeyboardEvent keyboardEvent, Vector2D mousePos)
{
	// predicts player next position & tileFunc checks for collision with that coordinate and returns a bool accordingly.
	if (!cheatCollision) {
		if (keyboardEvent == KeyboardEvent::KEY_PRESSED) {
			if (KeyCodes::KEY_UP == keyCodes) {
				tileFunc(pointer, transform.position.x, transform.position.y - 128);
			}
			else if (KeyCodes::KEY_LEFT == keyCodes) {
				tileFunc(pointer, transform.position.x - 128, transform.position.y);
			}
			else if (KeyCodes::KEY_RIGHT == keyCodes) {
				tileFunc(pointer, transform.position.x + 128, transform.position.y);
			}
			else if (KeyCodes::KEY_DOWN == keyCodes) {
				tileFunc(pointer, transform.position.x, transform.position.y + 128);
			}
		}
	}

	if (keyboardEvent == KeyboardEvent::KEY_PRESSED && keyCodes == KeyCodes::KEY_UP || keyCodes == KeyCodes::KEY_LEFT || keyCodes == KeyCodes::KEY_RIGHT || keyCodes == KeyCodes::KEY_DOWN)
	{
		currentDirection = keyCodes;
	}

	if (keyboardEvent == KeyboardEvent::KEY_PRESSED && !tileCollision)
	{
		handleKeyPressed(keyCodes);
	}

	else if (keyboardEvent == KeyboardEvent::KEY_RELEASED)
	{
		handleKeyReleased(keyCodes);
	}

	// resets collision for next move with collsion check.
	tileCollision = false;
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
	case KeyCodes::KEY_W:
		moveUp();
		break;
	case KeyCodes::KEY_S:
		moveDown();
		break;
	case KeyCodes::KEY_A:
		moveLeft();
		break;
	case KeyCodes::KEY_D:
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
		handleInteraction();
		break;
	case KeyCodes::KEY_G:
		if (this->texture == "player_m")
		{
			m_gc->setTexture("player_f");
			this->texture = "player_f";
		}
		else
		{
			m_gc->setTexture("player_m");
			this->texture = "player_m";
		}
		break;
	case KeyCodes::KEY_C:
		if (!cheatCollision) { cheatCollision = true; std::cout << "Cheat collision turned on." << std::endl; }
		else { cheatCollision = false; std::cout << "Cheat collision turned off." << std::endl; }
		break;
	default:
		break;
	}
}

void Player::handleInteraction() {
	if (KeyCodes::KEY_UP == currentDirection) {
		eqManagerFunc(pointer, transform.position.x, transform.position.y - 128);
	}
	else if (KeyCodes::KEY_LEFT == currentDirection) {
		eqManagerFunc(pointer, transform.position.x - 128, transform.position.y);
	}
	else if (KeyCodes::KEY_RIGHT == currentDirection) {
		eqManagerFunc(pointer, transform.position.x + 128, transform.position.y);
	}
	else if (KeyCodes::KEY_DOWN == currentDirection) {
		eqManagerFunc(pointer, transform.position.x, transform.position.y + 128);
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
	case KeyCodes::KEY_W:
		m_gc->playAnimation(4, 3, animationSpeed, false);
		break;
	case KeyCodes::KEY_S:
		m_gc->playAnimation(0, 3, animationSpeed, false);
		break;
	case KeyCodes::KEY_A:
		m_gc->playAnimation(5, 3, animationSpeed, false);
		break;
	case KeyCodes::KEY_D:
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
	transform.position.y -= baseMovementSpeed;
	m_gc.get()->transform.position = transform.position;
	runActivated ? m_gc->playAnimation(7, 3, animationSpeed, false) : m_gc->playAnimation(2, 4, animationSpeed, false);
	func(pointer, transform.position.x, transform.position.y);
}

/// <summary>
/// This method moves the character down by changing the sprite animation and adjusting the Y coordinate
/// Running or walk animation will be used based on the runActivated boolean value.
/// </summary>
void Player::moveDown()
{
	transform.position.y += baseMovementSpeed;
	m_gc.get()->transform.position = transform.position;
	runActivated ? m_gc->playAnimation(6, 3, animationSpeed, false) : m_gc->playAnimation(1, 4, animationSpeed, false);
	func(pointer, transform.position.x, transform.position.y);
}

/// <summary>
/// This method moves the character left by changing the sprite animation and adjusting the X coordinate
/// Running or walk animation will be used based on the runActivated boolean value.
/// </summary>
void Player::moveLeft()
{
	transform.position.x -= baseMovementSpeed;
	m_gc.get()->transform.position = transform.position;
	runActivated ? m_gc->playAnimation(8, 3, animationSpeed, false) : m_gc->playAnimation(3, 4, animationSpeed, false);
	func(pointer, transform.position.x, transform.position.y);
}

/// <summary>
/// This method moves the character right by changing the sprite animation and adjusting the X coordinate
/// Running or walk animation will be used based on the runActivated boolean value.
/// </summary>
void Player::moveRight()
{
	transform.position.x += baseMovementSpeed;
	m_gc.get()->transform.position = transform.position;
	runActivated ? m_gc->playAnimation(8, 3, animationSpeed, true) : m_gc->playAnimation(3, 4, animationSpeed, true);
	func(pointer, transform.position.x, transform.position.y);
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
		baseMovementSpeed = 256;
		std::cout << " runningshoes enabled" << std::endl;
	}
	else
	{
		runActivated = false;
		baseMovementSpeed = 128;
		std::cout << " runningshoes disabled" << std::endl;
	}
	//std::cout << runningActivated << " runningshoes" << std::endl;
}

void Player::staticTileCallbackFunction(void* p)
{
	((Player*)p)->setToTrue();

}

void Player::setToTrue()
{
	tileCollision = true;
}

void Player::damagePlayer(int damage) {}

void Player::updateCaughtPokemon(int pokemonId) {}

void Player::update() {}
