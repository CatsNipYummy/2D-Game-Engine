#include "entity.h"
#include <iostream>

// Constructor
Entity::Entity(std::string name)
{
    m_sName = name;
}

void Entity::setName (std::string name) {
    m_sName = name;
}

// Get Name
std::string Entity::name() {
    if (!m_sName.empty()) {
        return m_sName;
    }
    return 0;
}

// Add Component
void Entity::addComponent(Component *component) {
    std::cerr<<"Component "<< component->name();
    m_vComponents.push_back(component);
}

// Remove Component
void Entity::removeComponent(Component *component) {
    Component toBeDeleted = *component;

    for (int i = 0; i < m_vComponents.size(); i++) {
        if (*m_vComponents[i] == toBeDeleted) {
            m_vComponents.erase(m_vComponents.begin() + i);
        }
    }
}

// Get All Components
std::vector<Component*> Entity::getAllComponents() {
    return m_vComponents;
}

// Set Position
void Entity::setPosition(SDL_Point position) {
    m_pPosition = position;
}

