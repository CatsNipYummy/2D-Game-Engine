#ifndef Window_H
#define Window_H

#include <string>
#include<SDL2/SDL.h>
#include<renderer.h>


class Window
{
    Entity *m_character;
    Sprite *m_SpriteComponent;

public:
    bool m_bQuit=false;
    SDL_Event m_Event;
    Window();
    void createWindow(int height, int width, std::string name);
    virtual double update(SDL_Window *win);
};

#endif // Window_H
