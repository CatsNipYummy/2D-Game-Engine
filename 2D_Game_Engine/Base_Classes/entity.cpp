#include "entity.h"

// Constructor
Entity::Entity(std::string name)
{
    m_sName = name;
}

// Get Name
std::string Entity::getName() {
    if (!m_sName.empty()) {
        return m_sName;
    }
}
