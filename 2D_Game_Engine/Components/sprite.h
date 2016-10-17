#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <vector>
#include "component.h"
#include <SDL2/SDL.h>
#include "transform.h"
class Sprite : public Component
{
    std::string m_sName;
    SDL_Point m_pPosition;
    SDL_Rect m_rFrame;
    SDL_Texture *m_tTexture;
    SDL_Surface *m_sSurface;

public:
    Sprite();
    Sprite(const Sprite &sprite2);
    void setName (std::string name);
    std::string name ();

    void setPosition (SDL_Point position);
    SDL_Point position();

    void setFrame (SDL_Rect frame);
    SDL_Rect frame();

    void loadBMPFromString (std::string fileName);
    void update(int deltaTime, Transform* transform);
};

#endif // SPRITE_H
