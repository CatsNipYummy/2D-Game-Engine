#include "coreengine.h"
#include <SDL2/SDL.h>
#include<iostream>
#include<timer.h>
#include<renderer.h>

//SDL_Event m_Event;
//bool m_bQuit=false;

static SDL_Renderer* m_Renderer;


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



        CoreEngine::update(win);


    SDL_DestroyRenderer(m_Renderer);
        SDL_DestroyWindow(win);
        SDL_Quit();
}

int CoreEngine::update(SDL_Window *win)
{
    Timer timer;
    Renderer* r=new Renderer(win);
    m_Renderer=r->getRenderer();

    m_character = new Entity("Character");
    m_SpriteComponent = new Sprite();
    m_SpriteComponent->setName("Sprite_Component");

    m_SpriteComponent->setPosition({10,10});
    m_SpriteComponent->loadBMPFromString("/home/milind/Pictures/blah.bmp");

    m_character->addComponent(m_SpriteComponent);

    while (!m_bQuit) {
        // Input
        float deltaTime=timer.printFPS();

        std::vector<Component> components = m_character->getAllComponents();

        for (int i = 0; i < components.size(); i++) {
            Component c = components[i];
            c.update(deltaTime);

//            std::cerr<<"Name "<< component.name()<<"\n";
//            Sprite spriteComponent = static_cast<Sprite>(component);
//            spriteComponent.update(deltaTime);

        }

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
}
