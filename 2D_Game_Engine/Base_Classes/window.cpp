#include "window.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "timer.h"
#include "renderer.h"
#include "entitymanager.h"

const int PLAYER_VELOCITY = 10;
const int MAP_WIDTH = 1300;
const int MAP_HEIGHT = 779;

static SDL_Renderer *m_Renderer;

Window::Window()
{
    
}

void Window::createWindow(int height, int width, std::string name)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }
    
    m_iScreenWidth = width;
    m_iScreenHeight = height;
    
    SDL_Window *win = SDL_CreateWindow(name.c_str(), 100, 100, width, height, SDL_WINDOW_SHOWN);
    if (win == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    else {
        m_iScreenWidth = width;
        m_iScreenHeight = height;
        
        start(win);
    }
    
    Window::update(win);
    
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void Window::start(SDL_Window *win) {
    Renderer *r = new Renderer(win);
    m_Renderer = r->getRenderer();
    
    // Background
    m_eBackground = new Entity("Background");
    m_eBackground->transform->setPosition({0,0});
    m_eBackground->transform->setScale({1, 1});
    
    m_sBackgroundSpriteComponent = new Sprite();
    m_sBackgroundSpriteComponent->setName("Background_Sprite");
    m_sBackgroundSpriteComponent->loadBMPFromString("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/background.bmp");
    
    m_eBackground->addComponent(m_sBackgroundSpriteComponent);
    
    EntityManager::addEntity(m_eBackground);
    
    // Create the player
    m_Player = new Player();
    
    // Add game camera
    m_Camera = new Camera({0, 0, m_iScreenWidth, m_iScreenHeight});
}

double Window::update(SDL_Window *win)
{
    Timer timer;
    
    while (!m_bQuit) {
        
        // Input
        double deltaTime=timer.printFPS();
        
        std::vector<Entity> entityList = EntityManager::getAllEntities();
        
        for (std::vector<Entity>::iterator it = entityList.begin(); it != entityList.end(); ++it) {
            Entity *eachEntity = &*it;
            std::vector<Component*> components = eachEntity->getAllComponents();
            
            for (std::vector<Component*>::iterator it2 = components.begin(); it2 != components.end(); ++it2) {
                Component *c = *it2;
                eachEntity->transform->m_tPosition = {eachEntity->transform->m_tPosition.x, eachEntity->transform->m_tPosition.y};
                c->update(deltaTime, eachEntity->transform);
            }
        }
        
        // Camera
        Sprite *characterSprite = (Sprite*) m_Player->getComponent("Sprite_Component");
        if (characterSprite) {
            m_Camera->setX((m_Player->transform->m_tPosition.x + characterSprite->frame().w / 2) - m_iScreenWidth / 2);
            m_Camera->setY((m_Player->transform->m_tPosition.y + characterSprite->frame().h / 2) - m_iScreenHeight / 2);
        }
        
        //Keep the camera in bounds
        if(m_Camera->x() < 0 )
        {
            m_Camera->setX(0);
        }
        if(m_Camera->y() < 0 )
        {
            m_Camera->setY(0);
        }
        if(m_Camera->x() > MAP_WIDTH - m_Camera->rect().w)
        {
            m_Camera->setX(MAP_WIDTH - m_Camera->rect().w);
        }
        if(m_Camera->y() > MAP_HEIGHT - m_Camera->rect().h)
        {
            m_Camera->setY(MAP_HEIGHT - m_Camera->rect().h);
        }
        
        m_sBackgroundSpriteComponent->setFrame(m_Camera->rect());
        SDL_Point tempPoint = {m_Camera->rect().x, m_Camera->rect().y};
        m_eBackground->transform->setPosition(tempPoint);
        
        while (SDL_PollEvent(&m_Event)) {
            switch (m_Event.type) {
                case SDL_QUIT:
                    m_bQuit = true;
                    break;
                    
                case SDL_KEYUP:
                {
                    switch(m_Event.key.keysym.sym)
                    {
                        case SDLK_RIGHT:
                            xVel = 0;
                            break;
                        case SDLK_LEFT:
                            xVel = 0;
                            break;
                        case SDLK_UP:
                            yVel = 0;
                            break;
                        case SDLK_DOWN:
                            yVel = 0;
                            break;
                        default:
                            break;
                    }
                    break;
                }
                case SDL_KEYDOWN:
                {
                    switch(m_Event.key.keysym.sym)
                    {
                        case SDLK_RIGHT:
                            xVel += PLAYER_VELOCITY;
                            if(xVel > 2 * PLAYER_VELOCITY)
                                xVel = 2 * PLAYER_VELOCITY;
                            break;
                            
                        case SDLK_LEFT:
                            xVel -= PLAYER_VELOCITY;
                            if(xVel < -2*PLAYER_VELOCITY)
                                xVel = -2 * PLAYER_VELOCITY;
                            break;
                            
                        case SDLK_UP:
                            yVel += PLAYER_VELOCITY;
                            if(yVel > -2 * PLAYER_VELOCITY)
                                yVel = -2 * PLAYER_VELOCITY;
                        break;
                            
                        case SDLK_DOWN:
                            yVel -= PLAYER_VELOCITY;
                            if(yVel < 2*PLAYER_VELOCITY)
                                yVel = 2 * PLAYER_VELOCITY;
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
        
        // Move Player
        SDL_Point playerTransform = {static_cast<int>(m_Player->transform->m_tPosition.x + xVel),
            static_cast<int>(m_Player->transform->m_tPosition.y + yVel)};
        
        playerTransform.x -= m_Camera->x();
        playerTransform.y -= m_Camera->y();
        
        m_Player->transform->m_tPosition.x = playerTransform.x;
        m_Player->transform->m_tPosition.y = playerTransform.y;
        
        
//        m_Player->transform->m_tPosition.x += xVel;
//        m_Player->transform->m_tPosition.y += yVel;
        
        SDL_RenderPresent(m_Renderer);
        SDL_RenderClear(m_Renderer);
        
    }
    return 0;
}

