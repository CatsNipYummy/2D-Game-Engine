#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <vector>
#include "component.h"
#include <SDL2/SDL.h>

class Sprite : public Component
{
    std::string m_sName;
    SDL_Point m_pPosition;
    SDL_Texture *m_tTexture;

public:
    Sprite();
    Sprite(const Sprite &sprite2);
    void setName (std::string name);
    std::string name ();
    void setPosition (SDL_Point position);
    void loadBMPFromString (std::string fileName);
};

#endif // SPRITE_H
