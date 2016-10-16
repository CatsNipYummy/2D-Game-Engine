#ifndef COREENGINE_H
#define COREENGINE_H

#include <string>
#include<SDL2/SDL.h>
#include<renderer.h>

class CoreEngine
{
    Entity *m_character;
    Sprite *m_SpriteComponent;

public:
    bool m_bQuit=false;
    SDL_Event m_Event;
    CoreEngine();
    void createWindow(int height, int width, std::string name);
    virtual int update(SDL_Window *win);
};

#endif // COREENGINE_H
