#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <vector>
#include "component.h"
#include <SDL2/SDL.h>
#include "transform.h"
//#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_image.h>

class Sprite : public Component
{
    std::string m_sName;
    SDL_Point m_pPosition;
    SDL_Surface *m_sSurface;
    SDL_Rect m_rFrame;
    SDL_Rect subRect;
    SDL_Texture *m_tTexture;
    bool m_bFlip = false;

public:
    Sprite();
    ~Sprite();
    Sprite(const Sprite &sprite2);
    void setName (std::string name);
    std::string name ();
    void setPosition (SDL_Point position);
    SDL_Point position();
    void setFrame (SDL_Rect frame);
    SDL_Rect frame();
//    void loadBMPFromString (std::string fileName);
    //void update(float deltaTime, Transform* transform);
    void update(float deltaTime, Transform* transform);
    void update(float deltaTime, Transform* transform, int x, int y);
    void update(float deltaTime, Transform* transform, int x, int y, SDL_Rect* rect);
    void setSubRect(SDL_Rect sRect);
    SDL_Rect getSubRect();
    void loadSprite(std::string spriteName);
    void setFlip(bool flip);
};

#endif // SPRITE_H
