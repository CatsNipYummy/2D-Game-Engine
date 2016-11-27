#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "transform.h"
#include "entity.h"

class Entity;

class Component
{
    std::string m_sName;
    bool m_bActive;
    Entity *m_Entity;

protected:

public:
    Component();
    // Copy constructor
    Component(const Component &comp2);
    virtual void setName (std::string name);
    std::string name ();
    void setActive(bool active);
    Entity* entity();
    void setEntity(Entity *entity);
    bool operator == (Component const& component);
    virtual void update(float deltaTime, Transform* transform);
    virtual void update(float deltaTime, Transform* transform, int x, int y);
    virtual void update(float deltaTime, Transform* transform, int x, int y, SDL_Rect* rect);
};

#endif // COMPONENT_H
