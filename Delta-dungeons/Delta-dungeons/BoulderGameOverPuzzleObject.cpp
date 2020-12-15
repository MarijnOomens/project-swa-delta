#include "BoulderGameOverPuzzleObject.h"

BoulderGameOverPuzzleObject::BoulderGameOverPuzzleObject(int x, int y, const std::string& texture)
{
	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);

	gc->imageDimensions = { 32, 32 };
	gc->transform = transform;
	gc->isScreen = false;

	this->components.emplace_back(gc);
}

void BoulderGameOverPuzzleObject::handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void BoulderGameOverPuzzleObject::interact(std::shared_ptr<BehaviourObject> interactor)
{
	auto object = dynamic_cast<BoulderPuzzleObject*>(interactor.get());
	if (object != nullptr)
	{
		SceneLoader::getInstance().loadScene("GameOverScreen", "", true);
	}
}

void BoulderGameOverPuzzleObject::registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) {}

void BoulderGameOverPuzzleObject::setParent() {}

void BoulderGameOverPuzzleObject::start() {}

void BoulderGameOverPuzzleObject::update() {}