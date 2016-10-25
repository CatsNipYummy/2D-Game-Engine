#ifndef TRANSFORM_H
#define TRANSFORM_H

#include<iostream>
#include<SDL2/SDL.h>

class Transform
{
public:
    SDL_Point m_tPosition;
    SDL_Point m_tScale;
    SDL_Point m_tRotation;
    SDL_Rect m_rRect;

public:
    Transform();
    void setPosition(SDL_Point pos);
    void setScale(SDL_Point scale);
    void setRotation(SDL_Point rot);

    void setRect (SDL_Rect rect);
    SDL_Rect rect ();
};

#endif // TRANSFORM_H
