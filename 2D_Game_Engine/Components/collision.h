#ifndef COLLISION_H
#define COLLISION_H

#include "component.h"
#include "entity.h"

const bool DEBUG_ON = true;

class Collision : public Component
{
private:
    SDL_Rect m_rect;
    bool m_bDidCollide;

public:
    Collision();
    void update(int deltaTime, Transform* transform);
    void checkCollision();
    void setCollide(bool collide);
    bool didCollide ();
    void setRect (SDL_Rect rect);
    SDL_Rect rect();
};

#endif // COLLISION_H
