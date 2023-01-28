#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Engine
{
    private:
        std::string m_title;
        bool m_isRunning;
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        
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
};