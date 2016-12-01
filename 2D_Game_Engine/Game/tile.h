#ifndef TILE_H
#define TILE_H

#include <SDL2/SDL.h>
#include "entity.h"
#include "entitymanager.h"
#include "component.h"
#include "sprite.h"
#include "collisionmanager.h"

class Tile:public Entity
{
private :
    SDL_Rect mBox;
    int m_Type;

    Sprite *m_TileSpriteComponent;
public:
    Tile(int x, int y, int tileType);
    SDL_Rect getTile();
    int getType();
    void update(float deltaTime, Transform* transform, SDL_Rect &camera);
};

#endif // TILE_H
