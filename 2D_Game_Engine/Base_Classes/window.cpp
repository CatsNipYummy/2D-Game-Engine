#include "window.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "timer.h"
#include "renderer.h"
#include "entitymanager.h"
#include "collisionmanager.h"
#include <string>

const int PLAYER_VELOCITY = 1;
const int MAP_WIDTH = 1300;
const int MAP_HEIGHT = 779;
const int TILE_WIDTH = 80;
const int TILE_HEIGHT = 80;
const int SPRITE_SIZE=4;

static SDL_Renderer *m_Renderer;

Window::Window()
{

}

void Window::loadLevel(std::string levelName)
{
    std::vector<int> levelPixels;

    char ch;
    std::ifstream levelFile;
//    levelFile.open("/home/milind/Pictures/level1.txt");
    levelFile.open("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/level1.txt");
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

    //int currentX=0;
    //int currentY=0;
    for(int j = 0;j < height;j++)
    {
        for(int i=0;i < width;i++)
        {
            m_eBackground = new Entity("Background" + i + j);
            m_eBackground->transform->setPosition({i*TILE_WIDTH,j*TILE_HEIGHT});
            m_eBackground->transform->setScale({1, 1});

            m_sBackgroundSpriteComponent = new Sprite();
            m_sBackgroundSpriteComponent->setName("Background_Sprite");
        //    m_sBackgroundSpriteComponent->loadBMPFromString("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/background.bmp");
            std::string fileName;
            switch(pixelsArray[i][j])
            {
                case 0:
                    fileName="/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/blue.png";
                            break;
            case 1:
                fileName="/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/pink.png";
                        break;
            case 2:
                fileName="/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/green.png";
                        break;
            default:
                break;
            }
//            m_sBackgroundSpriteComponent->loadSprite(fileName);

//            m_sBackgroundSpriteComponent->loadBMPFromString("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/blah.bmp");
//            m_sBackgroundSpriteComponent->loadBMPFromString("/home/milind/Pictures/blah.bmp");

            m_eBackground->addComponent(m_sBackgroundSpriteComponent);

            EntityManager::addEntity(m_eBackground);

            /*m_eBackgroundTiles = new Entity("Background Tile");
            miniSprites[i][j] = new Sprite();
            miniSprites[i][j]->loadBMPFromString("/home/milind/Pictures/blah.bmp");
            miniSprites[i][j]->setFrame({currentX, currentY, TILE_WIDTH,TILE_HEIGHT});

            int modVal=pixelsArray[i][j] % SPRITE_SIZE;
            int divVal=pixelsArray[i][j] / SPRITE_SIZE;
            miniSprites[i][j]->setSubRect({divVal*TILE_WIDTH, modVal*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT});
            currentX+=TILE_WIDTH;
            m_eBackgroundTiles->addComponent(miniSprites[i][j]);
            std::cerr<<"Created";*/
        }
        //currentY+=TILE_WIDTH;
        //currentX = 0;
    }
}


void Window::createWindow(int height, int width, std::string name)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }

    if (IMG_Init(IMG_INIT_PNG) != 0){
        std::cout << "IMG_INIT Error: " << SDL_GetError() << std::endl;
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
    m_sBackgroundSpriteComponent->setEntity(m_eBackground);
    m_sBackgroundSpriteComponent->setName("Background_Sprite");
    m_sBackgroundSpriteComponent->loadSprite("/home/milind/Desktop/2D_Game_Engine/2D-Game-Engine/2D_Game_Engine/Assets/background.png");

//    m_sBackgroundSpriteComponent->loadSprite("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/background.png");
//    m_sBackgroundSpriteComponent->loadBMPFromString("/home/milind/Pictures/background.bmp");
    m_eBackground->addComponent(m_sBackgroundSpriteComponent);

    EntityManager::addEntity(m_eBackground);

//     Window::loadLevel("level1.txt");

    // Create the player
    m_Player = new Player();
    m_PlayerCollision = new Collision();
    m_PlayerCollision->setName("Player_Collision");
    m_PlayerCollision->setEntity(m_Player);
    m_PlayerCollision->setRect({50,50, 100,100});
    m_PlayerCollision->setRect(m_Player->transform->rect());
    m_Player->addComponent(m_PlayerCollision);
    EntityManager::addEntity(m_Player);
    CollisionManager::addCollision(m_PlayerCollision);

    // Enemy
    m_Enemy = new Entity("Enemy");
    m_Enemy->transform->setPosition({200,200});
    m_Enemy->transform->setScale({1, 1});

    m_enemySpriteComponent = new Sprite();
    m_enemySpriteComponent->setName("Enemy_Sprite");
    m_enemySpriteComponent->setFrame({200, 200, 20, 20});\
    m_enemySpriteComponent->loadSprite("/home/milind/Desktop/2D_Game_Engine/2D-Game-Engine/2D_Game_Engine/Assets/character.png");
//    m_enemySpriteComponent->loadSprite("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/character.png");
//    m_enemySpriteComponent->loadBMPFromString("/home/milind/Pictures/dot.bmp");
    m_Enemy->addComponent(m_enemySpriteComponent);

    m_EnemyCollision = new Collision();
    m_EnemyCollision->setName("Enemy_Collision");
//    m_EnemyCollision->setRect(m_enemySpriteComponent->frame());
    m_EnemyCollision->setRect({m_enemySpriteComponent->frame().x - 5,
                              m_enemySpriteComponent->frame().y - 5,
                              m_enemySpriteComponent->frame().w + 5,
                              m_enemySpriteComponent->frame().h + 5});

    m_Enemy->addComponent(m_EnemyCollision);

    EntityManager::addEntity(m_Enemy);
    CollisionManager::addCollision(m_EnemyCollision);

    // Add game camera
    m_Camera = new Camera({0, 0, m_iScreenWidth, m_iScreenHeight});
}

double Window::update(SDL_Window *win)
{
    Timer timer;
    Collision* col=(Collision*)m_Player->getComponent("Player_Collision");

    while (!m_bQuit) {

        // Input
        double deltaTime = timer.printFPS();

        std::vector<Entity> entityList = EntityManager::getAllEntities();

        for (std::vector<Entity>::iterator it = entityList.begin(); it != entityList.end(); ++it) {
            Entity *eachEntity = &*it;
            std::vector<Component*> components = eachEntity->getAllComponents();

            for (std::vector<Component*>::iterator it2 = components.begin(); it2 != components.end(); ++it2) {
                Component *c = *it2;
                //eachEntity->transform->m_tPosition = {eachEntity->transform->m_tPosition.x, eachEntity->transform->m_tPosition.y};
                if (c->name().find("Collision") != std::string::npos) {
                    Collision *col = (Collision*) c;
                    CollisionManager::checkCollision(col);

                }
                c->update(deltaTime, eachEntity->transform);
            }
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
                        case SDLK_RIGHT: {
                            xVelR = 0;
                            break;
                        }
                        case SDLK_LEFT:
                            xVelL = 0;
                            break;
                        case SDLK_UP:
                            yVelU = 0;
                            break;
                        case SDLK_DOWN:
                            yVelD = 0;
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
                    {
                        if(xVelR>0)
                        {
                            right=true;
                            left=false;
                        }
                        if(xVelR > 2 * PLAYER_VELOCITY)
                                xVelR = 2 * PLAYER_VELOCITY;

                            xVelR+=PLAYER_VELOCITY;
                        break;
}
                        case SDLK_LEFT:
                        {
                            if(xVelL<0)
                            {
                                left=true;
                                right=false;
                            }
                            if(xVelL < -2*PLAYER_VELOCITY)
                            {
                                xVelL = -2 * PLAYER_VELOCITY;
                            }
                             xVelL -= PLAYER_VELOCITY;


                            break;
}
                        case SDLK_UP:
                    {
                            if(yVelU<0)
                            {
                                up=true;
                                down=false;
                            }
                            if(yVelU < -2 * PLAYER_VELOCITY){
                                yVelU = -2 * PLAYER_VELOCITY;}
                            yVelU -= PLAYER_VELOCITY;
                            break;
    }
                        case SDLK_DOWN:
                    {
                            if(yVelD>0)
                            {
                                down=true;
                                up=false;
                            }
                            if(yVelD > 2*PLAYER_VELOCITY)
                            {
                                yVelD = 2 * PLAYER_VELOCITY;
                            }
                             yVelD += PLAYER_VELOCITY;

                            break;
                }
                        default:
                            break;
                    }
                    break;
                }
                default:
                    break;
            }
        }
        if(col->didCollide() && right)
            xVelR=0;
        if(col->didCollide() && left)
            xVelL=0;
        if(col->didCollide() && down)
            yVelD=0;
        if(col->didCollide() && up)
            yVelU=0;
        m_Player->transform->m_tPosition.x += (xVelL+xVelR);
        m_Player->transform->m_tPosition.y += (yVelD+yVelU);

        m_Player->transform->setRect({m_Player->transform->m_tPosition.x, m_Player->transform->m_tPosition.y, 20, 20});
        m_PlayerCollision->setRect({m_Player->transform->rect().x - 5, m_Player->transform->rect().y - 5,
                                   m_Player->transform->rect().w + 5, m_Player->transform->rect().h + 5});

        SDL_RenderPresent(m_Renderer);
        SDL_RenderClear(m_Renderer);

    }
    return 0;
}

