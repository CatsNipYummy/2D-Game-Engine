#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>
#include <iostream>
#include "entity.h"

class Camera : Entity
{
private:
    SDL_Rect m_rRect;
public:
    Camera(SDL_Rect rect);
    SDL_Rect rect();
    int x();
    int y();
    void setX(int x);
    void setY(int y);
};

#endif // CAMERA_H
