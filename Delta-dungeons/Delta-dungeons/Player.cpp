#include "Player.h"
#include "Runningshoes.h"

/// <summary>
/// This class defines everything that has to do with the player character. Textures, input handling, health and caught Pok�mon
/// are all defined in the Player class. Interaction with the player's equipment is handled here too.
/// 
/// </summary>

/// <summary>
/// Creates the running and boomerang equipments. And added to the equipment vector list.
/// Defines the movementspeed and the runactivated bool
/// Creates the graphicscomponent for the player sprite and saves the texturename and png location, width, height
/// </summary>
Player::Player(cbCamera f, const void* p): func(f), pointer(p)
{
	std::string textureBoomerang ="boomerang" ;
	std::unique_ptr<Runningshoes> running = std::make_unique<Runningshoes>(staticEquipmentCallbackFunction, this);
	std::unique_ptr<Boomerang> boomerang = std::make_unique<Boomerang>(textureBoomerang);

	//addEquipment(std::move(running));
	addEquipment(std::move(boomerang));

	baseMovementSpeed = 64;
	runActivated = false;

	this->transform.position.x = 1024;
	this->transform.position.y = 768;

	this->textures.try_emplace("player_m", "Assets/player2_m_anims.png");
	this->textures.try_emplace("player_f", "Assets/player_f_anims.png");
	this->textures.try_emplace(textureBoomerang, "Assets/HUD/Boomerang.png");
	this->texture = "player_m";

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("player_m");
	gc->isScreen = false;
	gc->transform = this->transform;
	gc->imageDimensions = { 32, 32 };
	gc->transform.scale.multiply({ 4, 4 });
	gc->playAnimation(0, 3, animationSpeed, false);

	this->components.emplace_back(gc);
}

/// <summary>
///	handleInput receives the keyboard input through keycodes and keyboardevents
/// </summary> 
/// <param name="Keycodes are enums and will be used to decide what action the user will make."></param>
/// <param name="keyboardEvent">KeyboardEvent will decide if handleKeyPressed or handleKeyReleased will be used</param>
void Player::handleInput(const KeyCodes &keyCodes, const KeyboardEvent &keyboardEvent, Vector2D &mousePos)
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
void Player::handleKeyPressed(const KeyCodes& keyCodes)
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
			gc->setTexture("player_f");
			this->texture = "npc";
		}
		else {
			gc->setTexture("player_m");
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
void Player::handleKeyReleased(const KeyCodes& keyCodes)
{
	switch (keyCodes)
	{
	case KeyCodes::KEY_UP:
		gc->playAnimation(4, 3, animationSpeed, false);
		break;
	case KeyCodes::KEY_DOWN:
		gc->playAnimation(0, 3, animationSpeed, false);
		break;
	case KeyCodes::KEY_LEFT:
		gc->playAnimation(5, 3, animationSpeed, false);
		break;
	case KeyCodes::KEY_RIGHT:
		gc->playAnimation(5, 3, animationSpeed, true);
		break;
	default:
		break;
	}
}

void Player::update() {}

/// <summary>
/// This method moves the character up by changing the sprite animation and adjusting the Y coordinate
/// Running or walk animation will be used based on the runActivated boolean value.
/// </summary>
void Player::moveUp()
{
	transform.position.y -= baseMovementSpeed;
	gc.get()->transform.position = transform.position;
	runActivated ? gc->playAnimation(7, 3, animationSpeed, false) :
		gc->playAnimation(2, 4, animationSpeed, false);
	func(pointer, transform.position.x, transform.position.y);
}

/// <summary>
/// This method moves the character down by changing the sprite animation and adjusting the Y coordinate
/// Running or walk animation will be used based on the runActivated boolean value.
/// </summary>
void Player::moveDown()
{
	transform.position.y += baseMovementSpeed;
	gc.get()->transform.position = transform.position;
	runActivated ? gc->playAnimation(6, 3, animationSpeed, false) :
		gc->playAnimation(1, 4, animationSpeed, false);
	func(pointer, transform.position.x, transform.position.y);
}

/// <summary>
/// This method moves the character left by changing the sprite animation and adjusting the X coordinate
/// Running or walk animation will be used based on the runActivated boolean value.
/// </summary>
void Player::moveLeft()
{
	transform.position.x -= baseMovementSpeed;
	gc.get()->transform.position = transform.position;
	runActivated ? gc->playAnimation(8, 3, animationSpeed, false) :
		gc->playAnimation(3, 4, animationSpeed, false);
	func(pointer, transform.position.x, transform.position.y);
}

/// <summary>
/// This method moves the character right by changing the sprite animation and adjusting the X coordinate
/// Running or walk animation will be used based on the runActivated boolean value.
/// </summary>
void Player::moveRight()
{
	transform.position.x += baseMovementSpeed;
	gc.get()->transform.position = transform.position;
	runActivated ? gc->playAnimation(8, 3, animationSpeed, true) :
		gc->playAnimation(3, 4, animationSpeed, true);
	func(pointer, transform.position.x, transform.position.y);
}

/// <summary>
/// This method is a setter to add an equipment to the vector list called Equipment
/// </summary>
/// <param name="item">The equipment that will bed added</param>
void Player::addEquipment(std::unique_ptr<IEquipment> item)
{
	equipment.emplace_back(std::move(item));
}

void Player::damagePlayer(int damage) {}

void::Player::updateCaughtPokemon(int pokemonId) {}

std::vector<std::string> Player::getItems()
{
	std::vector<std::string> items;
	for (auto& item : equipment)
	{
		items.push_back(item->texturePath);
	}
	return items;
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
		baseMovementSpeed = 128;
	}
	else 
	{
		runActivated = false;
		baseMovementSpeed = 64;
	}
}