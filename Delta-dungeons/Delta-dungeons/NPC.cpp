#include "NPC.h"

NPC::NPC(int x, int y, const std::string& texture, const std::vector<std::string> d): dialogue(d)
{
	this->textures.try_emplace("dialogue_box", "Assets/Dialogue/text_box.png");

	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });
	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);
	gc->imageDimensions = { 32, 32 };
	gc->transform = this->transform;
	gc->playAnimation(0, 3, animationSpeed, false);
	gc->isScreen = false;

	stp = std::make_shared<StopStrategy>();
	cc = std::make_shared<CollidingComponent>(stp);
	cc->tag = "npc";
	cc->transform.position = this->transform.position;

	this->components.emplace_back(gc);
	this->components.emplace_back(cc);
}

void NPC::interact(std::shared_ptr<BehaviourObject> interactor)
{
	playAnimation(interactor->transform);
	std::shared_ptr<DialoguePopup> dialoguePopup = std::make_shared<DialoguePopup>(getRandomDialogue());
	std::vector<std::shared_ptr<BehaviourObject>> objects;
	objects.emplace_back(dialoguePopup);
	for (auto& c : dialoguePopup->getComponentsRecursive())
	{
		objects.emplace_back(c);
	}
	SceneModifier::getInstance().replaceScene("Dialogue", objects);
	SceneLoader::getInstance().addOverlayScene("Dialogue");
}

void NPC::playAnimation(Transform t)
{
	if (t.position.x > transform.position.x)
	{
		gc->playAnimation(5, 3, animationSpeed, true);
	}
	else if (t.position.x < transform.position.x)
	{
		gc->playAnimation(5, 3, animationSpeed, false);
	}
	if (t.position.y > transform.position.y)
	{
		gc->playAnimation(0, 3, animationSpeed, false);
	}
	else if (t.position.y < transform.position.y)
	{
		gc->playAnimation(4, 3, animationSpeed, false);
	}
}

std::string NPC::getRandomDialogue()
{
	int randomDialogue = rand() % (dialogue.size());
	return dialogue[randomDialogue];
}


void NPC::setParent() {
	cc->parent = shared_from_this();
}

void NPC::registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger, bool isPuzzleEntrance, bool isPuzzleExit) {}

void NPC::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void NPC::update() {}

void NPC::start() {}
