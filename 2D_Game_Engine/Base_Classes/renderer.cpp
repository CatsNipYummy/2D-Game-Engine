#include "renderer.h"
#include<iostream>

static SDL_Renderer *m_Renderer;
Renderer::Renderer(SDL_Window *win)
{
    m_Renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_Renderer == nullptr){
        SDL_DestroyWindow(win);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
}

SDL_Renderer* Renderer::getRenderer()
{
    if (m_Renderer)
        return m_Renderer;
    return 0;
}


