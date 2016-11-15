#ifndef WORLD_H
#define WORLD_H

#include "component.h"
#include "entity.h"
#include "player.h"

class World : public Component
{
private:
    float m_pGravity;

    Entity *m_entity;
    Player *m_Player;

    float m_fTempX, m_fTempY;

public:
    World();
    void update(float deltaTime, Transform* transform);
    void setEntity(Entity *entity);
    void setPlayer(Player *player);
};

#endif // WORLD_H
