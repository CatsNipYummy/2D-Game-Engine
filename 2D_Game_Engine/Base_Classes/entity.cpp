#include "entity.h"

// Constructor
Entity::Entity(string Name)
{

}

// Get Name
string Entity::getName() {
    if (m_sName != NULL) {
        return m_sName;
    }
}
