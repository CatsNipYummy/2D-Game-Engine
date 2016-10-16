#ifndef RENDERER_H
#define RENDERER_H

#include<SDL2/SDL.h>

class Renderer
{
private:

public:
    Renderer(SDL_Window* win);
    SDL_Renderer* getRenderer();
};

#endif // RENDERER_H
