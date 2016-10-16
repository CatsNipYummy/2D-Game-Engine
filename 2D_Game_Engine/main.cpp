#include <iostream>
<<<<<<< HEAD
#include<coreengine.h>
=======
#include "entity.h"
#include "sprite.h"

int width = 640;
int height = 480;
bool m_bQuit = false;

static SDL_Renderer *m_Renderer;
SDL_Event m_Event;
>>>>>>> a7f4d9f2cc8d50c0f40de16e3d19fd700aaf736b

Entity *m_character;
Sprite *m_SpriteComponent;

int main()
{
<<<<<<< HEAD
    CoreEngine coreEngine;
    coreEngine.createWindow(480, 640, "Test");
=======
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
            std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        }

        SDL_Window *win = SDL_CreateWindow("Test", 100, 100, width, height, SDL_WINDOW_SHOWN);
        if (win == nullptr){
            std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
        }

        m_Renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (m_Renderer == nullptr){
            SDL_DestroyWindow(win);
            std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
        }

        m_character = new Entity("Character");
        m_SpriteComponent = new Sprite();
        m_SpriteComponent->setName("Sprite Component");

        m_SpriteComponent->setPosition({10,10});
        m_SpriteComponent->loadBMPFromString("test.bmp");

        m_character->addComponent(m_SpriteComponent);

        while (!m_bQuit) {
                // Input
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

    SDL_RenderPresent(m_Renderer);
    SDL_RenderClear(m_Renderer);

    SDL_DestroyRenderer(m_Renderer);
        SDL_DestroyWindow(win);
        SDL_Quit();
>>>>>>> a7f4d9f2cc8d50c0f40de16e3d19fd700aaf736b
}
