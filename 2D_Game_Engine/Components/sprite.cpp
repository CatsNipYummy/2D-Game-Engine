#include "sprite.h"
#include "renderer.h"
#include <iostream>
#include <SDL2_image/SDL_image.h>
//#include <SDL2/SDL_image.h>

Sprite::Sprite()
{
    SDL_RectEmpty(&subRect);
    SDL_RectEmpty(&m_rFrame);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(m_tTexture);
        SDL_FreeSurface(m_sSurface);
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

void Sprite::setSubRect(SDL_Rect sRect)
{
    subRect=sRect;
}

SDL_Rect Sprite::getSubRect()
{
return subRect;
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
void Sprite::update(float deltaTime, Transform* transform) {
    if (m_tTexture) {
        if(subRect.w == 0 || subRect.h == 0) {
            m_rFrame = {transform->m_tPosition.x, transform->m_tPosition.y, m_sSurface->w, m_sSurface->h};
            SDL_RenderCopyEx( Renderer::getRenderer(), m_tTexture, NULL, &m_rFrame, 0.0, NULL, SDL_FLIP_NONE );
        }
        else
        {
            if (!m_bFlip)
                SDL_RenderCopyEx( Renderer::getRenderer(), m_tTexture, &subRect, &m_rFrame, 0.0, NULL, SDL_FLIP_NONE );
            else
                SDL_RenderCopyEx( Renderer::getRenderer(), m_tTexture, &subRect, &m_rFrame, 0.0, NULL, SDL_FLIP_HORIZONTAL );

        }
    }
}

// Load File
//void Sprite::loadBMPFromString(std::string fileName) {

//    m_sSurface = SDL_LoadBMP(fileName.c_str());
//    if (m_sSurface == nullptr){
//        std::cout << "SDL_LoadBMP Error: " << SDL_GetError()<<"\n";
//        return;
//    }
//    m_tTexture = SDL_CreateTextureFromSurface(Renderer::getRenderer(), m_sSurface);
//    if (m_tTexture == nullptr){
//        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
//        return;
//    }
//}

void Sprite::loadSprite(std::string spriteName) {

    m_sSurface = IMG_Load(spriteName.c_str());
    m_tTexture = SDL_CreateTextureFromSurface(Renderer::getRenderer(), m_sSurface);

    if (m_sSurface == nullptr){
        std::cout << "IMG_Load Error: " << SDL_GetError()<<"\n";
        return;
    }

    m_tTexture = SDL_CreateTextureFromSurface(Renderer::getRenderer(), m_sSurface);
    if (m_tTexture == nullptr){
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return;
    }
}

void Sprite::setFlip(bool flip) {
    m_bFlip = flip;
}
