#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "transform.h"

class Component
{
    std::string m_sName;
    bool m_bActive;

protected:

public:
    Component();
    // Copy constructor
    Component(const Component &comp2);
    virtual void setName (std::string name);
    std::string name ();
    void setActive(bool active);

    bool operator == (Component const& component);
    virtual void update(int deltaTime, Transform* transform);
};

#endif // COMPONENT_H
