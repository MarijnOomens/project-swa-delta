#define SDL_MAIN_HANDLED
#include "EngineController.h"

int main(int argc, char* argv[])
{
    std::unique_ptr<EngineController> engineController = std::make_unique<EngineController>();
      return 0;
}
