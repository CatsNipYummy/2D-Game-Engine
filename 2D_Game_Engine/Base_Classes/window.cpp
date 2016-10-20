#include "window.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "timer.h"
#include "renderer.h"
#include "entitymanager.h"

const int PLAYER_VELOCITY = 10;
const int MAP_WIDTH = 1300;
const int MAP_HEIGHT = 779;
const int TILE_WIDTH = 256;
const int TILE_HEIGHT = 256;

static SDL_Renderer* m_Renderer;

Window::Window()
{

}

void Window::loadLevel(std::string levelName)
{
    std::vector<int> levelPixels;

    char ch;
    std::ifstream levelFile;
    levelFile.open("/home/milind/Pictures/"+ levelName);
    while(levelFile >> std::skipws >> ch)
    {
        levelPixels.push_back((int)ch-48);

    }

    int k=0;
    for(int j = 0;j < height;j++)
    {
        for(int i = 0;i < width;i++)
        {
            pixelsArray[i][j]=levelPixels[k];
            k++;
            std::cerr<<pixelsArray[i][j]<<std::endl;
        }
    }
    m_eBackground = new Entity("Background");
    m_eBackground->transform->setPosition({0,0});
    m_eBackground->transform->setScale({1, 1});

    m_sBackgroundSpriteComponent = new Sprite();
    m_sBackgroundSpriteComponent->setName("Background_Sprite");
    m_sBackgroundSpriteComponent->loadBMPFromString("/home/milind/Pictures/blah.bmp");

    m_eBackground->addComponent(m_sBackgroundSpriteComponent);

    EntityManager::addEntity(m_eBackground);

    for(int j = 0;j < height;j++)
    {
        for(int i=0;i < width;i++)
        {
            m_sBackgroundSpriteComponent->setFrame({0, 0,TILE_WIDTH,TILE_HEIGHT});
            m_sBackgroundSpriteComponent->setSubRect({i*width, j*height,TILE_WIDTH,TILE_HEIGHT});
            //SDL_RenderCopyEx( Renderer::getRenderer(), m_sBackgroundSpriteComponent->m_tTexture, NULL, &(m_sBackgroundSpriteComponent->m_rFrame), 0.0, NULL, SDL_FLIP_NONE );

        }
    }
}


void Window::createWindow(int height, int width, std::string name)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
            std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        }

        SDL_Window *win = SDL_CreateWindow(name.c_str(), 100, 100, width, height, SDL_WINDOW_SHOWN);
        if (win == nullptr){
            std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
        }

        m_iScreenWidth = width;
        m_iScreenHeight = height;

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

    Window::loadLevel("level1.txt");

    // Background
    m_eBackground = new Entity("Background");
    m_eBackground->transform->setPosition({0,0});
    m_eBackground->transform->setScale({1, 1});

    m_sBackgroundSpriteComponent = new Sprite();
    m_sBackgroundSpriteComponent->setName("Background_Sprite");
    m_sBackgroundSpriteComponent->loadBMPFromString("/home/milind/Pictures/blah.bmp");

    m_eBackground->addComponent(m_sBackgroundSpriteComponent);

    EntityManager::addEntity(m_eBackground);

    // Create the player
    m_Player = new Player();

    // Add game camera
    m_Camera = new Camera({0, 0, MAP_WIDTH, MAP_HEIGHT});

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
//        Sprite *characterSprite = (Sprite*) m_eCharacter->getComponent("Sprite_Component");
//        if (characterSprite) {
//            m_Camera->setX((characterSprite->position().x + characterSprite->frame().w / 2) - m_iScreenWidth / 2);
//            m_Camera->setY((characterSprite->position().y + characterSprite->frame().h / 2) - m_iScreenHeight / 2);

//        }
//
//       //Keep the camera in bounds
//       if(m_Camera->x() < 0 )
//       {
//           m_Camera->setX(0);
//       }
//       if(m_Camera->y() < 0 )
//       {
//           m_Camera->setY(0);
//       }
//       if(m_Camera->x() > MAP_WIDTH - m_Camera->rect().w)
//       {
//           m_Camera->setX(MAP_WIDTH - m_Camera->rect().w);
//       }
//       if(m_Camera->y() > MAP_HEIGHT - m_Camera->rect().h)
//       {
//           m_Camera->setY(MAP_HEIGHT - m_Camera->rect().h);
//       }

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
                                    //xVel -= CHARACTER_VELOCITY;
                                    xVel=0;
                                    break;
                                case SDLK_LEFT:
                                    //xVel += CHARACTER_VELOCITY;
                                    xVel=0;
                                    break;
                                case SDLK_UP:
                                    //yVel += CHARACTER_VELOCITY;
                                    yVel=0;
                                    break;
                                case SDLK_DOWN:
                                    //yVel -= CHARACTER_VELOCITY;
                                    yVel=0;
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
                                if(xVel>2*PLAYER_VELOCITY)
                                    xVel=2*PLAYER_VELOCITY;
                                break;

                            case SDLK_LEFT:
                                xVel -= PLAYER_VELOCITY;
                                if(xVel<-2*PLAYER_VELOCITY)
                                    xVel=-2*PLAYER_VELOCITY;
                                break;
                            case SDLK_UP:
                                yVel -= PLAYER_VELOCITY;
                                if(yVel<-2*PLAYER_VELOCITY)
                                    yVel=-2*PLAYER_VELOCITY;
                                break;
                            case SDLK_DOWN:
                                yVel += PLAYER_VELOCITY;
                                if(yVel>2*PLAYER_VELOCITY)
                                    yVel=2*PLAYER_VELOCITY;
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
        m_Player->transform->m_tPosition.x += xVel;
        m_Player->transform->m_tPosition.y += yVel;

       SDL_RenderPresent(m_Renderer);
       SDL_RenderClear(m_Renderer);

    }
    return 0;
}

