#define SDL_MAIN_HANDLED
#include "EngineController.h"
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

int main(int argc, char* argv[])
{
    _CrtDumpMemoryLeaks();
    std::unique_ptr<EngineController> engineController = std::make_unique<EngineController>();
      return 0;
}
