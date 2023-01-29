#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Engine
{
    private:
        Uint16 m_targetFrametime;
        bool m_isRunning;
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        
    public:
        Engine();
        ~Engine();

        void Init(std::string title, int width, int height, bool fullscreen, Uint16 targetFrametime);
        void GameLoop();
        void Update();
        void Render();
        void Clean();
        void HandleEvents();
        void UpdateSettings();

        bool isRunning() { return m_isRunning; }
};