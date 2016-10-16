#include "sprite.h"
#include "renderer.h"
#include <iostream>

Sprite::Sprite()
{

}

Sprite::Sprite(const Sprite &sprite2) {
    m_sName = sprite2.m_sName;
    m_pPosition = sprite2.m_pPosition;
    m_tTexture = sprite2.m_tTexture;
}

std::string Sprite::name () {
    return m_sName;
}

void Sprite::setName(std::string name) {
    m_sName = name;
    Component::setName(name);
}

// Set Position
void Sprite::setPosition(SDL_Point position) {
    m_pPosition = position;
}

// Get Position
SDL_Point Sprite::position() {
    return m_pPosition;
}

// Set Frame
void Sprite::setFrame (SDL_Rect frame) {
    m_pPosition = {frame.x, frame.y};
    m_rFrame = frame;
}

// Get Frame
SDL_Rect Sprite::frame() {
    return m_rFrame;
}

// Update Loop
void Sprite::update(int deltaTime) {
    if (m_tTexture) {
        if (SDL_RectEmpty(&m_rFrame)) {
            m_rFrame = {0, 0, m_sSurface->w, m_sSurface->h};
        }
        SDL_RenderCopy(Renderer::getRenderer(), m_tTexture, NULL, &m_rFrame);
    }
}

// Load File
void Sprite::loadBMPFromString(std::string fileName) {
    m_sSurface = SDL_LoadBMP(fileName.c_str());
    if (m_sSurface == nullptr){
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError()<<"\n";
        return;
    }

    m_tTexture = SDL_CreateTextureFromSurface(Renderer::getRenderer(), m_sSurface);
    SDL_FreeSurface(m_sSurface);
    if (m_tTexture == nullptr){
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return;
    }
}
