#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include <component.h>

class Entity
{
    std::string m_sName;
public:
    Entity(std::string name);
    std::string getName();
};

#endif // ENTITY_H
