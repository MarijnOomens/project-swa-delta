#pragma once
#include <vector>
#include <memory>
#include "PuzzleObject.h"
#include "ParserData.h"
#include "BoulderPuzzleObject.h"
class Puzzle
{
public:
	Puzzle() {}
	~Puzzle() {}

	//interactive object: 
		//door, trigger, boulder

	//deur die open kan gaan, //interact bevat opendoorBoolean check
	std::vector<std::shared_ptr<IInteractiveObject>> doors;

	//gameobject die checkt of iets op //interact bevat isPlaced check
	std::vector<std::shared_ptr<IInteractiveObject>> triggers;

	//boulder die gepushed kan worden, //interact bevat direction
	std::map<std::string, std::shared_ptr<IInteractiveObject>> boulders;

	//std::vector<std::shared_ptr<IInteractiveObject>> boulders;

	//verzamel alle behaviourobjects
	//en paas ze door 


	//interact->gaat pas open 
																			//check x, y, cast to door, settrue
	//player --- boulder -> interact(behaviourobject) --- func --- puzzle->doors->settrue() --- puzzle->checkTrue() --- opendoor 

	//todo
	//static method

	void createBoulder(std::shared_ptr<ParserData> parser);
	static void staticTriggerCallbackFunction(void* p, int x, int y);
	void trigger(int x, int y);

private:
};