#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <entity.h>
#include <component.h>
#include <vector>

class EntityManager
{
    std::vector<Component> m_vComponents;

public:
    EntityManager();
    void addComponentToEntity(Component &component, Entity &entity);
    void removeComponentFromEntity(Component &component, Entity &entity);
    std::vector<Component> getAllComponents(Entity &entity);
};

#endif // ENTITYMANAGER_H
