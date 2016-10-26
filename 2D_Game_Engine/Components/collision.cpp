#include "collision.h"
#include <iostream>
#include "renderer.h"

Collision::Collision()
{
    SDL_SetRenderDrawColor(Renderer::getRenderer(), 255, 0, 0 ,255);
}

// Update loop
void Collision::update(int deltaTime, Transform *transform) {
    checkCollision();
    if (DEBUG_ON) {
        SDL_RenderDrawLine(Renderer::getRenderer(), m_rect.x, m_rect.y, m_rect.x + (m_rect.w * 2), m_rect.y);
        SDL_RenderDrawLine(Renderer::getRenderer(), m_rect.x + (m_rect.w * 2), m_rect.y, m_rect.x + (m_rect.w * 2), m_rect.y + (m_rect.h * 2));
        SDL_RenderDrawLine(Renderer::getRenderer(), m_rect.x + (m_rect.w * 2), m_rect.y + (m_rect.h * 2), m_rect.x, m_rect.y + (m_rect.h * 2));
        SDL_RenderDrawLine(Renderer::getRenderer(), m_rect.x, m_rect.y + (m_rect.h * 2), m_rect.x, m_rect.y);
    }
}

void Collision::checkCollision() {
//    std::cerr<<"Collision "<< m_rect.x << " "<< m_rect.y<<" "<< m_rect.w<<" "<<m_rect.h;
}

void Collision::setCollide(bool collide) {
    m_bDidCollide = collide;
}

bool Collision::didCollide() {
    return m_bDidCollide;
}

void Collision::setRect(SDL_Rect rect) {
    m_rect = rect;
}

SDL_Rect Collision::rect() {
    return m_rect;
}
