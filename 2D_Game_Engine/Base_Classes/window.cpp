#include "window.h"
#include <SDL2/SDL.h>
#include<iostream>
#include<timer.h>
#include<renderer.h>

//SDL_Event m_Event;
//bool m_bQuit=false;

static SDL_Renderer* m_Renderer;


Window::Window()
{

}

void Window::createWindow(int height, int width, std::string name)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
            std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        }

        SDL_Window *win = SDL_CreateWindow("Test", 100, 100, width, height, SDL_WINDOW_SHOWN);
        if (win == nullptr){
            std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
        }



        Window::update(win);


    SDL_DestroyRenderer(m_Renderer);
        SDL_DestroyWindow(win);
        SDL_Quit();
}

double Window::update(SDL_Window *win)
{
    Timer timer;
    Renderer* r=new Renderer(win);
    m_Renderer=r->getRenderer();

    m_character = new Entity("Character");
    m_character->transform->setPosition({100,100});
    m_character->transform->setScale({1,1});

    m_SpriteComponent = new Sprite();
    m_SpriteComponent->setName("Sprite_Component");

    m_SpriteComponent->loadBMPFromString("/Users/anil/Downloads/Tutorials/30_scrolling/dot.bmp");

    m_character->addComponent(m_SpriteComponent);

    while (!m_bQuit) {
        // Input
        double deltaTime=timer.printFPS();

        std::vector<Component*> components = m_character->getAllComponents();

        for (int i = 0; i < components.size(); i++) {
            Component* c = components[i];
            m_character->transform->m_tPosition = {m_character->transform->m_tPosition.x, m_character->transform->m_tPosition.y};
            c->update(deltaTime, m_character->transform);
        }

        while (SDL_PollEvent(&m_Event)) {
            switch (m_Event.type) {
                case SDL_QUIT:
                    m_bQuit = true;
                    break;

                case SDL_KEYUP:
                {
                    break;
                }
                case SDL_KEYDOWN:
                {
                    switch(m_Event.key.keysym.sym)
                    {
                        case SDLK_RIGHT:
                            m_character->transform->m_tPosition.x += 10;
                            break;
                        case SDLK_LEFT:
                        m_character->transform->m_tPosition.x -= 10;
                            break;
                        case SDLK_UP:
                        m_character->transform->m_tPosition.y -= 10;
                        break;
                        case SDLK_DOWN:
                        m_character->transform->m_tPosition.y += 10;
                        break;
                    default:
                        break;
                    }

                    break;
                }
                default:
                    break;
            }
        }
           SDL_RenderPresent(m_Renderer);
           SDL_RenderClear(m_Renderer);

    }
}
