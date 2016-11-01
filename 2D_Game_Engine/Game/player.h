#ifndef PLAYER_H
#define PLAYER_H

#include <entity.h>
#include <entitymanager.h>
#include <component.h>
#include <sprite.h>
#include "animation.h"
#include "collision.h"
#include "collisionmanager.h"

class Player : public Entity
{
private:
    Sprite *m_sSpriteComponent;
    Animation *m_aAnimation;
    Collision *m_PlayerCollision;

public:
    Player();
};

#endif // PLAYER_H
