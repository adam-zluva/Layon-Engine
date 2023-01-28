#include <iostream>
#include "Engine.hpp"

const int WIDTH = 640, HEIGHT = 480;
const bool FULLSCREEN = false;

int main()
{
    Engine* engine = new Engine("Layon");

    engine->Init(WIDTH, HEIGHT, FULLSCREEN);

    while (engine->isRunning())
    {
        engine->HandleEvents();
        engine->Update();
        engine->Render();
    }

    engine->Clean();
    delete engine;

    return EXIT_SUCCESS;
}