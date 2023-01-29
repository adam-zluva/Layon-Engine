#include <iostream>
#include "Engine.hpp"

#define ENDLN "\n"

Engine::Engine() { }

Engine::~Engine() { }

void Engine::Init(std::string title, int width, int height, bool fullscreen, Uint16 targetFrametime)
{
    std::cout << "Engine - Init started." << ENDLN;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Engine - SDL Initialized!" << ENDLN;

        m_isRunning = true;
        m_targetFrametime = targetFrametime;

        int flags = 0;
        if (fullscreen) flags |= SDL_WINDOW_FULLSCREEN;

        m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            width, height, flags);
        if (m_window == NULL)
        {
            std::cerr << "Engine - Unable to create window. Details: " << SDL_GetError() << ENDLN;
            m_isRunning = false;
        } else { }

        m_renderer = SDL_CreateRenderer(m_window, -1, 0);
        if (m_renderer == NULL)
        {
            std::cerr << "Engine - Unable to create renderer. Details: " << SDL_GetError() << ENDLN;
            m_isRunning = false;
        } else
        {
            SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
        }
    }
}

void Engine::HandleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            m_isRunning = false;
            break;
        
        default:
            // std::cout << "Engine - Unknown event polled." << ENDLN;
            break;
    }
}

void Engine::GameLoop()
{
    Uint32 frameStart = 0;
    while (isRunning())
    {        
        Uint32 deltaTime = SDL_GetTicks() - frameStart;

        frameStart = SDL_GetTicks();
        HandleEvents();
        Update();
        Render();

        int delayTime = m_targetFrametime - (SDL_GetTicks() - frameStart);
        if (delayTime > 0) SDL_Delay(delayTime);

        Uint32 frameTime = SDL_GetTicks() - frameStart;
        std::cout << "Engine - Frame time: " << frameTime << ENDLN;
    }
}

void Engine::Update()
{
    
}

void Engine::Render()
{
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);
}

void Engine::UpdateSettings() { }

void Engine::Clean()
{
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
    std::cout << "Engine - Shutdown complete." << ENDLN;
}