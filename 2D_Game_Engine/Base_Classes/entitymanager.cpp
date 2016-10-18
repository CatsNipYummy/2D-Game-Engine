#include "entitymanager.h"

std::vector<Entity> EntityManager::m_vEntities;

void EntityManager::addEntity(Entity *entity) {
    EntityManager::m_vEntities.push_back(*entity);
}

std::vector<Entity> &EntityManager::getAllEntities() {
    return EntityManager::m_vEntities;
}
