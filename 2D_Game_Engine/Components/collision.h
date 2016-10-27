#ifndef COLLISION_H
#define COLLISION_H

#include "component.h"
#include "entity.h"

const bool DEBUG_ON = true;

class Collision : public Component
{
private:
    SDL_Rect m_rect;
    bool m_bDidCollide = false;
    bool m_bLeft = false;
    bool m_bRight = false;
    bool m_bTop = false;
    bool m_bBottom = false;
    SDL_Point contactPoint;

public:
    Collision();
    void update(int deltaTime, Transform* transform);
    void checkCollision();
    void setCollide(bool collide);
    bool didCollide ();
    void setRect (SDL_Rect rect);
    SDL_Rect rect();
    void setLeft(bool l);
    void setRight(bool r);
    void setTop(bool t);
    void setBottom(bool b);
    bool getLeft();
    bool getRight();
    bool getTop();
    bool getBottom();
    void setContactPoint(SDL_Point cp);
    SDL_Point getContactPoint();
};

#endif // COLLISION_H
