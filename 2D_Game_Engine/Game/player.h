#ifndef PLAYER_H
#define PLAYER_H

#include <entity.h>
#include <entitymanager.h>
#include <component.h>
#include <sprite.h>

class Player : public Entity
{
private:
    Entity *m_eCharacter;
    Sprite *m_sSpriteComponent;

public:
    Player();
};

#endif // PLAYER_H
