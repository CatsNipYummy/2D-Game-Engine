#ifndef Window_H
#define Window_H

#include<SDL2/SDL.h>
#include"renderer.h"
#include <string>
#include <fstream>
#include <iomanip>
#include "player.h"
#include "camera.h"

class Window
{
    const int height=2, width=4;
    int m_iScreenWidth, m_iScreenHeight;

    Player *m_Player;

    Entity *m_eCharacter;
    Entity *m_eBackground;
    Sprite *m_sBackgroundSpriteComponent;

    // Game camera
    Camera *m_Camera;

    float xVel=0, yVel=0;

public:
    bool m_bQuit=false;
    int pixelsArray[1000][1000];
    SDL_Event m_Event;
    Window();
    void createWindow(int height, int width, std::string name);
    virtual double update(SDL_Window *win);
    void loadLevel(std::string levelName);
};

#endif // Window_H
