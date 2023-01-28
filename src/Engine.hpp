#pragma once

#include <SDL2/SDL.h>
#include <iostream>

class Engine
{
    public:
        Engine(std::string title);
        ~Engine();

        void Init(int width, int height, bool fullscreen);
        void Update();
        void Render();
        void Clean();
        void HandleEvents();
        void UpdateSettings();

        bool isRunning() { return m_isRunning; }
    
    private:
        std::string m_title;
        bool m_isRunning;
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
};