#include "transform.h"

Transform::Transform()
{
    m_tPosition={0,0};
    m_tScale={1,1};
    m_tRotation={0,0};
}

void Transform::setPosition(SDL_Point pos)
{
    m_tPosition=pos;
}

void Transform::setRotation(SDL_Point rot)
{
    m_tRotation=rot;
}

void Transform::setScale(SDL_Point scale)
{
    m_tScale=scale;
}

SDL_Rect Transform::rect() {
    return m_rRect;
}

void Transform::setRect(SDL_Rect rect) {
    m_rRect = rect;
}

