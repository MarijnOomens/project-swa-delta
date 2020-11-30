#include "Player.h"

/// <summary>
/// This class defines everything that has to do with the player character. Textures, input handling, health and caught Pok�mon
/// are all defined in the Player class. Interaction with the player's equipment is handled here too.
/// </summary>
/// 
/// <summary>
/// Creates the running and boomerang equipments. And added to the equipment vector list.
/// Defines the movementspeed and the runactivated bool
/// Creates the graphicscomponent for the player sprite and saves the texturename and png location, width, height
/// </summary>
Player::Player(int spawnX, int spawnY, cbCollision collisionCB, cbNextLevel nextLevelcb, const cbCamera f, cbInteract interactCB, cbGameOver gameOverF, cbHUD hudCB, void* p)
: collisionFunc(collisionCB), nextLevelFunc(nextLevelcb), func(f), interactFunc(interactCB), gameOverFunc(gameOverF), hudFunc(hudCB), pointer(p)
{
	std::string textureBoomerang ="boomerangHUD" ;
	std::string textureRunning = "runningshoesHUD";
	std::unique_ptr<Boomerang> boomerang = std::make_unique<Boomerang>(textureBoomerang,staticBoomerangCallbackFunction, this);
	std::unique_ptr<RunningShoes> running = std::make_unique<RunningShoes>(staticRunningShoesCallbackFunction, this, textureRunning);
	equippedPokeball = std::make_shared<Pokeball>(staticPokeballCallbackFunction, this);


	addEquipment(std::move(running));
	addEquipment(std::move(boomerang));

	baseMovementSpeed = 128;
	runActivated = false;
	tileCollision = false;

	this->transform.position.x = spawnX*128;
	this->transform.position.y = spawnY*128;

	this->textures.try_emplace("player_m", "Assets/player2_m_anims.png");
	this->textures.try_emplace("player_f", "Assets/player_f_anims.png");
	this->textures.try_emplace(textureBoomerang, "Assets/HUD/Boomerang.png");
	this->textures.try_emplace(textureRunning, "Assets/HUD/Runningshoes.png");
	this->texture = "player_m";

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("player_m");
	gc->isScreen = false;
	gc->transform = this->transform;
	gc->imageDimensions = { 32, 32 };
	gc->transform.scale.multiply({ 4, 4 });
	gc->playAnimation(0, 3, animationSpeed, false);

	stp = std::make_shared<StopStrategy>();
	cc = std::make_shared<CollidingComponent>(stp);
	cc->tag = "player";
	cc->transform.position = this->transform.position;

	this->components.emplace_back(gc);
	this->components.emplace_back(cc);

	currentDirection = KeyCodes::KEY_DOWN;
}

/// <summary>
///	handleInput receives the keyboard input through keycodes and keyboardevents
/// </summary> 
/// <param name="Keycodes are enums and will be used to decide what action the user will make."></param>
/// <param name="keyboardEvent">KeyboardEvent will decide if handleKeyPressed or handleKeyReleased will be used</param>
void Player::handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)
{
	if (!DebugUtilities::getInstance().isCheatCollisionOn())
	{
	}

	if (keyboardEvent == KeyboardEvent::KEY_PRESSED && keyCodes == KeyCodes::KEY_UP || keyCodes == KeyCodes::KEY_LEFT || keyCodes == KeyCodes::KEY_RIGHT || keyCodes == KeyCodes::KEY_DOWN || keyCodes == KeyCodes::KEY_W || keyCodes == KeyCodes::KEY_S || keyCodes == KeyCodes::KEY_A || keyCodes == KeyCodes::KEY_D)
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
}

void Player::interact(std::shared_ptr<BehaviourObject> interactor) {}

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
			comp->use();
		}
		break;
	case KeyCodes::KEY_E:
		handleInteraction();
		break;
	case KeyCodes::KEY_B:
		eatBerry();
		break;
	case KeyCodes::KEY_G:
		if (this->texture == "player_m")
		{
			gc->setTexture("player_f");
			this->texture = "player_f";
		}
		else
		{
			gc->setTexture("player_m");
			this->texture = "player_m";
		}
		break;
	//skip collision kan later geimplementeerd worden
	//case KeyCodes::KEY_C:
	//	DebugUtilities::getInstance().toggleCheatCollision();
	//	break;
	case KeyCodes::KEY_C:
		equippedPokeball->use();
		break;
	default:
		break;
	}
}

void Player::handleInteraction()
{
	if (KeyCodes::KEY_UP == currentDirection || KeyCodes::KEY_W == currentDirection) {
		interactFunc(pointer, shared_from_this(), transform.position.x, transform.position.y - 128);
	}
	else if (KeyCodes::KEY_LEFT == currentDirection || KeyCodes::KEY_A == currentDirection) {
		interactFunc(pointer, shared_from_this(), transform.position.x - 128, transform.position.y);
	}
	else if (KeyCodes::KEY_RIGHT == currentDirection || KeyCodes::KEY_D == currentDirection) {
		interactFunc(pointer, shared_from_this(), transform.position.x + 128, transform.position.y);
	}
	else if (KeyCodes::KEY_DOWN == currentDirection || KeyCodes::KEY_S == currentDirection) {
		interactFunc(pointer, shared_from_this(), transform.position.x, transform.position.y + 128);
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
	case KeyCodes::KEY_W:
		gc->playAnimation(4, 3, animationSpeed, false);
		break;
	case KeyCodes::KEY_S:
		gc->playAnimation(0, 3, animationSpeed, false);
		break;
	case KeyCodes::KEY_A:
		gc->playAnimation(5, 3, animationSpeed, false);
		break;
	case KeyCodes::KEY_D:
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
	//de huidige positie bijhouden.
	collisionFunc(pointer, shared_from_this(), this->transform.position.x, this->transform.position.y - 128, KeyCodes::KEY_UP);
	if (!hasMoved) {
		transform.position.y -= baseMovementSpeed;
		cc->transform.position.y = this->transform.position.y;
		gc->transform.position = transform.position;

		runActivated ? gc->playAnimation(7, 3, animationSpeed, false) : gc->playAnimation(2, 4, animationSpeed, false);
		func(pointer, transform.position.x, transform.position.y);
	}
	hasMoved = false;
}

/// <summary>
/// This method moves the character down by changing the sprite animation and adjusting the Y coordinate
/// Running or walk animation will be used based on the runActivated boolean value.
/// </summary>
void Player::moveDown()
{
	collisionFunc(pointer, shared_from_this(), this->transform.position.x, this->transform.position.y + 128, KeyCodes::KEY_DOWN);
	if (!hasMoved) {
		transform.position.y += baseMovementSpeed;
		cc->transform.position.y = this->transform.position.y;
		gc->transform.position = transform.position;

		runActivated ? gc->playAnimation(6, 3, animationSpeed, false) : gc->playAnimation(1, 4, animationSpeed, false);
		func(pointer, transform.position.x, transform.position.y);
	}
	hasMoved = false;
}

/// <summary>
/// This method moves the character left by changing the sprite animation and adjusting the X coordinate
/// Running or walk animation will be used based on the runActivated boolean value.
/// </summary>
void Player::moveLeft()
{
	collisionFunc(pointer, shared_from_this(), this->transform.position.x - 128, this->transform.position.y, KeyCodes::KEY_LEFT);
	if (!hasMoved) {
		transform.position.x -= baseMovementSpeed;
		cc->transform.position.x = this->transform.position.x;
		gc->transform.position = transform.position;

		runActivated ? gc->playAnimation(8, 3, animationSpeed, false) : gc->playAnimation(3, 4, animationSpeed, false);
		func(pointer, transform.position.x, transform.position.y);
	}
	hasMoved = false;
}

/// <summary>
/// This method moves the character right by changing the sprite animation and adjusting the X coordinate
/// Running or walk animation will be used based on the runActivated boolean value.
/// </summary>
void Player::moveRight()
{
	collisionFunc(pointer, shared_from_this(), this->transform.position.x + 128, this->transform.position.y, KeyCodes::KEY_RIGHT);
	if(!hasMoved) {
		transform.position.x += baseMovementSpeed;
		cc->transform.position.x = this->transform.position.x;
		gc->transform.position = transform.position;

		runActivated ? gc->playAnimation(8, 3, animationSpeed, true) : gc->playAnimation(3, 4, animationSpeed, true);
		func(pointer, transform.position.x, transform.position.y);
	}
	hasMoved = false;
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
		items.push_back(item->texture);
	}
	return items;
}

std::shared_ptr<CollidingComponent> Player::getCollider() {
	return cc;
}

void Player::staticBoomerangCallbackFunction(void* p, const bool brActivated)
{
	((Player*)p)->boomerangCallbackFunction(brActivated);

}

void Player::boomerangCallbackFunction(const bool brActivated)
{
	if (brActivated) { boomerangActivated = true; }
	else { boomerangActivated = false; }
}

/// <summary>
/// Callbackmethod to call the runningShoesCallbackFunction.
/// </summary>
/// <param name="p">Is needed for the includes</param>
/// <param name="runningActivated">Boolean value for runActived Property</param>
void Player::staticRunningShoesCallbackFunction(void* p, const bool runningActivated)
{
	((Player*)p)->runningShoesCallbackFunction(runningActivated);

}

/// <summary>
/// This method changes the runActivated boolean and the baseMovementspeed based upon runningActivated
/// </summary>
/// <param name="runningActivated">This value will be used to set the runActivated property</param>
void Player::runningShoesCallbackFunction(const bool runningActivated)
{
	if (runningActivated)
	{
		runActivated = true;
		baseMovementSpeed = 256;
	}
	else
	{
		runActivated = false;
		baseMovementSpeed = 128;
	}
}

void Player::staticPokeballCallbackFunction(void* p)
{
	((Player*)p)->pokeballCallbackFunction();

}

void Player::pokeballCallbackFunction()
{
	std::cout << "i threw a pokeball" << std::endl;
}


void Player::registerHit() {
	if (health > 1) 
	{
		health--;
		hudFunc(pointer, health, amountOfBerries, amountOfPokeballs);
	}
	else if(health <= 1)
	{
		health = 0;
		hudFunc(pointer, health, amountOfBerries, amountOfPokeballs);
		gc->playAnimation(9, 4, animationSpeed, false);
		gameOverFunc(pointer);
	}
	
}

void Player::eatBerry() {
	
	if (health < maxHealth && amountOfBerries > 0) //maxHealth
	{
		health++;
		amountOfBerries--;
		hudFunc(pointer, health, amountOfBerries, amountOfPokeballs);
	}
}

void Player::addBerry() {
	
	amountOfBerries += 1;
	hudFunc(pointer, health, amountOfBerries, amountOfPokeballs);
}

void Player::addPokeball() {
	amountOfPokeballs += 1;
	hudFunc(pointer, health, amountOfBerries, amountOfPokeballs);
}

void Player::registerCollision(int x, int y, bool isDamaged, bool isTransitioned) {
	if (isDamaged) { registerHit(); }
	if (isTransitioned) { nextLevelFunc(pointer); }
	hasMoved = true;
}