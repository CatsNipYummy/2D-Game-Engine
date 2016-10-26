#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <iostream>
#include <vector>
#include <entity.h>
#include "collision.h"

class CollisionManager
{
private:
    static std::vector<Collision> m_vCollisionComponents;
//    DIRECTION m_CollisionDirection;
    bool m_bLeft;
    bool m_bRight;
    bool m_bTop;
    bool m_bBottom;

public:
    CollisionManager();
    static void addCollision(Collision *collision);
    static std::vector<Collision> &getAllCollisions();
    static void checkCollision(Collision *collision);

    enum DIRECTION {
        LEFT,
        RIGHT,
        TOP,
        BOTTOM
    };
};

#endif // COLLISIONMANAGER_H
