#ifndef RENDERER_H
#define RENDERER_H

#include<SDL2/SDL.h>

#include "entity.h"
#include "sprite.h"

class Renderer
{
private:

public:
    Renderer(SDL_Window* win);
    static SDL_Renderer* getRenderer();
};

#endif // RENDERER_H
