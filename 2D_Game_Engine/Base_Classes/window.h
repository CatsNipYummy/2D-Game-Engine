#ifndef Window_H
#define Window_H

#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include"renderer.h"
#include <string>
#include <fstream>
#include <iomanip>
#include "player.h"
#include "camera.h"
#include "collision.h"
#include "animation.h"

class Window
{
    const int height=2, width=4;
    int m_iScreenWidth, m_iScreenHeight;
    
    Player *m_Player;
    Collision *m_PlayerCollision;
    Animation *m_PlayerAnimationComponent;

    Entity *m_eBackground;
    Entity *m_eBackgroundTiles;

    Sprite *m_sBackgroundSpriteComponent;

    Entity *m_Enemy;
    Sprite *m_enemySpriteComponent;
    Collision *m_EnemyCollision;

    // Game camera
    Camera *m_Camera;

    bool m_bRightCollided = false;

    Sprite *miniSprites[4][2];

public:
    bool m_bQuit=false;
    float xVelL=0,xVelR=0,yVelU=0,yVelD=0;
    bool r=false, u=false;
    int pixelsArray[1000][1000];
    SDL_Event m_Event;
    Window();
    void createWindow(int height, int width, std::string name);
    void start(SDL_Window *win);
    virtual double update(SDL_Window *win);
    void loadLevel(std::string levelName);
};

#endif // Window_H
