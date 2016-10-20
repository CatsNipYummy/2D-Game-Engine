#include "component.h"
#include <iostream>

Component::Component() {

}

Component::Component(const Component &comp2) {
    m_sName = comp2.m_sName;
    m_bActive = comp2.m_bActive;
}

void Component::setName (std::string name) {
    m_sName = name;
}

std::string Component::name() {
    if (this->m_sName.empty())
        return 0;
    return this->m_sName;
}

void Component::update(int deltaTime, Transform* transform) {

}

void Component::setActive(bool active) {
    m_bActive = active;
}

bool Component::operator == (Component const& component) {
    //Component *comp = component;
    if (*this == component)
        return true;
    return false;
}
