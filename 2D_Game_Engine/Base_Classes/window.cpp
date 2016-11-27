#include "window.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "timer.h"
#include "renderer.h"
#include "entitymanager.h"
#include "collisionmanager.h"
#include <string>

const int PLAYER_VELOCITY = 1;
const int MAP_WIDTH = 6781;
const int MAP_HEIGHT = 1000;
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
    levelFile.open("/home/milind/Desktop/2D_Game_Engine/2D-Game-Engine/2D_Game_Engine/Assets/level1.txt");

    //    levelFile.open("/home/milind/Pictures/level1.txt");
    //levelFile.open("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/level1.txt");
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
                    fileName="/home/milind/Desktop/2D_Game_Engine/2D-Game-Engine/2D_Game_Engine/Assets/blue.png";
                            break;
            case 1:
                fileName="/home/milind/Desktop/2D_Game_Engine/2D-Game-Engine/2D_Game_Engine/Assets/pink.png";
                        break;
            case 2:
                fileName="/home/milind/Desktop/2D_Game_Engine/2D-Game-Engine/2D_Game_Engine/Assets/green.png";
                        break;
            default:
                break;
            }
            m_sBackgroundSpriteComponent->loadSprite(fileName);
            m_EnemyCollision = new Collision();
            m_EnemyCollision->setName("Enemy_Collision" + i + j);
        //    m_EnemyCollision->setRect(m_enemySpriteComponent->frame());
            m_EnemyCollision->setRect({m_sBackgroundSpriteComponent->frame().x - 5,
                                      m_sBackgroundSpriteComponent->frame().y - 5,
                                      m_sBackgroundSpriteComponent->frame().w + 5,
                                      m_sBackgroundSpriteComponent->frame().h + 5});

            m_eBackground->addComponent(m_EnemyCollision);

//            m_sBackgroundSpriteComponent->loadBMPFromString("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/blah.bmp");
//            m_sBackgroundSpriteComponent->loadBMPFromString("/home/milind/Pictures/blah.bmp");
            
            
            //            m_sBackgroundSpriteComponent->loadBMPFromString("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/blah.bmp");
            //            m_sBackgroundSpriteComponent->loadBMPFromString("/home/milind/Pictures/blah.bmp");

            m_eBackground->addComponent(m_sBackgroundSpriteComponent);
            
            EntityManager::addEntity(m_eBackground);


            //EntityManager::addEntity(m_Enemy);
            CollisionManager::addCollision(m_EnemyCollision);

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
    m_sBackgroundSpriteComponent->loadSprite("/home/milind/Pictures/bg.png");

        //m_sBackgroundSpriteComponent->loadBMPFromString("/home/milind/Pictures/background.bmp");
    m_eBackground->addComponent(m_sBackgroundSpriteComponent);
    
    EntityManager::addEntity(m_eBackground);

    // Window::loadLevel("level1.txt");

    // Create the player
    m_Player = new Player();
    m_PlayerCollision = new Collision();
    m_PlayerCollision->setName("Player_Collision");
    m_PlayerCollision->setEntity(m_Player);
    m_PlayerCollision->setRect({50,50, 100,100});
    m_PlayerCollision->setRect(m_Player->transform->rect());
    m_Player->addComponent(m_PlayerCollision);
    
    CollisionManager::addCollision(m_PlayerCollision);
    
    EntityManager::addEntity(m_Player);
    
    // World
    m_worldEntity = new Entity("Character");
    m_worldComponent = new World();
    m_worldComponent->setName("World_Component");
    m_worldComponent->setEntity(m_worldEntity);
    m_worldComponent->setPlayer(m_Player);
    m_worldEntity->addComponent(m_worldComponent);
    EntityManager::addEntity(m_worldEntity);
    
    
    // Enemy
    m_Enemy = new Entity("Enemy");
    m_Enemy->transform->setPosition({200,200});
    m_Enemy->transform->setScale({1, 1});

    m_enemySpriteComponent = new Sprite();
    m_enemySpriteComponent->setName("Enemy_Sprite");
    m_enemySpriteComponent->setFrame({200, 200, 20, 20});
    //m_enemySpriteComponent->loadSprite("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/character.png");
    m_enemySpriteComponent->loadSprite("/home/milind/Desktop/2D_Game_Engine/2D-Game-Engine/2D_Game_Engine/Assets/character.png");

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
    m_Camera = new Camera({0, 0, 640, 480});
    
}

double Window::update(SDL_Window *win)
{
    Timer timer;
    Collision* col=(Collision*)m_Player->getComponent("Player_Collision");
    
    while (!m_bQuit) {
        
        // Input
        double deltaTime = timer.printFPS();
        
        std::vector<Entity> entityList = EntityManager::getAllEntities();
        
        /*for (std::vector<Entity>::iterator it = entityList.begin(); it != entityList.end(); ++it) {
            Entity *eachEntity = &*it;
            std::vector<Component*> components = eachEntity->getAllComponents();
            
            for (std::vector<Component*>::iterator it2 = components.begin(); it2 != components.end(); ++it2) {
                Component *c = *it2;
                if (c->name().find("Collision") != std::string::npos) {
                    Collision *col = (Collision*) c;
                    CollisionManager::checkCollision(col);
                    
                }
                c->update(deltaTime, eachEntity->transform);
            }
        }*/

        while (SDL_PollEvent(&m_Event)) {
            
            m_Player->setInput(m_Event);
            
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
                            right=false;
                            break;
                        }
                        case SDLK_LEFT:
                            xVelL = 0;
                            left=false;
                            break;
                        case SDLK_UP:
                            yVelU = 0;
                            up=false;
                            break;
                        case SDLK_DOWN:
                            yVelD = 0;
                            down=false;
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
                            if(yVelU > -2 * PLAYER_VELOCITY){
                                yVelU = -2 * PLAYER_VELOCITY;}
                           yVelU += PLAYER_VELOCITY;
                            break;
                        }
                        case SDLK_DOWN:
                        {
                        if(yVelD>0)
                                                    {
                                                        down=true;
                                                        up=false;
                                                    }


                            if(yVelD < 2*PLAYER_VELOCITY)
                            {
                                yVelD = 2 * PLAYER_VELOCITY;
                            }
                              yVelD -= PLAYER_VELOCITY;
                            
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
            }
        }

        if(col->didCollide() && right && xVelR>0)
        {
            xVelR=0;
        }
        if(col->didCollide() && left && xVelL<0)
        {
            xVelL=0;
        }
        if(col->didCollide() && down && yVelD>0)
        {
            yVelD=0;
        }
        if(col->didCollide() && up && yVelU<0)
        {
            yVelU=0;
        }
        m_Player->transform->m_tPosition.x += (xVelL+xVelR);
        m_Player->transform->m_tPosition.y += (yVelD+yVelU);

       if ((xVelL+xVelR) !=0) {
            m_Player->transform->m_tPosition.x += (xVelL+xVelR);
            Sprite *spriteTemp = (Sprite*) m_Player->getComponent("Sprite_Component");
            if (xVelL+xVelR>0) {
                spriteTemp->setFlip(false);
            }
            else {
                //m_Player->setFlip(true);
                spriteTemp->setFlip(true);
            }
        }
        if ((yVelU+yVelD) != 0) {
            m_Player->transform->m_tPosition.y += yVelU+yVelD;
        }

        m_Camera->setX((m_Player->transform->rect().x + m_Player->transform->rect().w/ 2 ) - 320);
        m_Camera->setY((m_Player->transform->rect().y + m_Player->transform->rect().h / 2 ) - 240);

        //Keep the camera in bounds
        if( m_Camera->x() < 0 )
        {
            m_Camera->setX(0);
        }
        if( m_Camera->y() < 0 )
        {
            m_Camera->setY(0);
        }
        if( m_Camera->x() > MAP_WIDTH - m_Camera->rect().w )
        {
            m_Camera->setX(MAP_WIDTH-m_Camera->rect().w);
        }
        if( m_Camera->y() > MAP_HEIGHT - m_Camera->rect().h )
        {
            m_Camera->setY(MAP_HEIGHT-m_Camera->rect().h);
        }
        SDL_Rect r=m_Camera->rect();
        m_eBackground->getComponent("Background_Sprite")->update(deltaTime,m_eBackground->transform,0,0,&r);

        int xoffset=m_Player->transform->m_tPosition.x-m_Camera->x();
        int yoffset=m_Player->transform->m_tPosition.y-m_Camera->y();

        m_Player->getComponent("Sprite_Component")->update(deltaTime,m_Player->transform,xoffset,yoffset);

        m_Player->getComponent("Animation_Component")->update(deltaTime,m_Player->transform);

        
        m_Player->transform->setRect({m_Player->transform->m_tPosition.x, m_Player->transform->m_tPosition.y, 30, 41});
        m_PlayerCollision->setRect({m_Player->transform->rect().x, m_Player->transform->rect().y,
            m_Player->transform->rect().w, m_Player->transform->rect().h});

        SDL_RenderPresent(m_Renderer);
        SDL_RenderClear(m_Renderer);
        
    }
    return 0;
}

