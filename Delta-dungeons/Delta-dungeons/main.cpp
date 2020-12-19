#define SDL_MAIN_HANDLED
#define _CRTDBG_MAP_ALLOC  
#include "GameManager.h"

int main(int argc, char* argv[])
{
	GameManager gameManager;
	_CrtDumpMemoryLeaks();
}
