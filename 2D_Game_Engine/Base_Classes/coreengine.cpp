#include "coreengine.h"
#include <SDL2/SDL.h>
#include<iostream>
#include<timer.h>
#include<renderer.h>

SDL_Event m_Event;
bool m_bQuit=false;


CoreEngine::CoreEngine()
{

}

void CoreEngine::createWindow(int height, int width, std::string name)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
            std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        }

        SDL_Window *win = SDL_CreateWindow("Test", 100, 100, width, height, SDL_WINDOW_SHOWN);
        if (win == nullptr){
            std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
        }

        Timer timer;

        Renderer* r=new Renderer(win);
        static SDL_Renderer* m_Renderer=r->getRenderer();

        while (!m_bQuit) {
                // Input
            timer.printFPS();
                while (SDL_PollEvent(&m_Event)) {
                    switch (m_Event.type) {
                        case SDL_QUIT:
                            m_bQuit = true;
                            break;

                        default:
                            break;
                    }
                }
                SDL_RenderPresent(m_Renderer);
                SDL_RenderClear(m_Renderer);
        }

    SDL_DestroyRenderer(m_Renderer);
        SDL_DestroyWindow(win);
        SDL_Quit();

}
