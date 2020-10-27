#define SDL_MAIN_HANDLED
#include "EngineController.h"
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include "GameManager.h"

int main(int argc, char* argv[])
{
    std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();
    _CrtDumpMemoryLeaks();
      return 0;
}
