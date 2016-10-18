#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "entity.h"
#include "component.h"
#include <vector>

class EntityManager
{
private:
    static std::vector<Entity> m_vEntities;
    EntityManager() {}

public:
    static void addEntity(Entity *entity);
    static std::vector<Entity> &getAllEntities();
};

#endif // ENTITYMANAGER_H
