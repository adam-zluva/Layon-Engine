#include <iostream>
#include "Engine.hpp"

#define ENGINE_TITLE "Layon Engine"

const int WIDTH = 640, HEIGHT = 480;
const bool FULLSCREEN = false;

int main()
{
    Engine* engine = new Engine();

    engine->Init(ENGINE_TITLE, WIDTH, HEIGHT, FULLSCREEN, 16);
    engine->GameLoop();
    engine->Clean();

    delete engine;
    return EXIT_SUCCESS;
}