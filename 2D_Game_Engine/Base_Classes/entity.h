#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include "component.h"
#include <SDL2/SDL.h>
#include "transform.h"

class Component;

class Entity
{
    std::string m_sName;
    std::vector<Component*> m_vComponents;

protected:
    SDL_Point m_pPosition;
    SDL_Surface *m_eSurface;

public:
    Entity(std::string name);
    Transform *transform;
    virtual std::string name();
    virtual void setName (std::string name);

    void setPosition (SDL_Point position);

    void addComponent(Component *component);
    void removeComponent(Component *component);
    Component *getComponent (std::string name);
    std::vector<Component*> getAllComponents();
};

#endif // ENTITY_H
