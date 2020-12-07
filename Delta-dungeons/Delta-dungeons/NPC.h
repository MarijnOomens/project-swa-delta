#pragma once
#include "IInteractiveObject.h"
#include "CollidingComponent.h"
#include <string>
#include <map>
#include <GraphicsComponent.h>
#include "StopStrategy.h"
#include "DialoguePopup.h"
#include "SceneLoader.h"
#include "SceneModifier.h"

class NPC : public IInteractiveObject
{
public:
	NPC(int x, int y, const std::string& texture, const std::vector<std::string> d);

	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) override;
	void setParent() override;
	void playAnimation(Transform t);
	std::string getRandomDialogue();

protected:
	std::string sfxPath;

private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	const int animationSpeed = 180;
	const std::vector<std::string> dialogue;
};