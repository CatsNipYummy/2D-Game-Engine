#include "sprite.h"
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

// Load File
void Sprite::loadBMPFromString(std::string fileName) {
//        SDL_Surface *bmp = SDL_LoadBMP(fileName.c_str());
//        if (bmp == nullptr){
//            std::cout << "SDL_LoadBMP Error: " << SDL_GetError()<<"\n";
//            return;
//        }

//        m_tTexture = SDL_CreateTextureFromSurface(ren, bmp);
//        SDL_FreeSurface(bmp);
//        if (m_tTexture == nullptr){
//            std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
//            return;
//        }

//        SDL_RenderCopy(ren, tex, NULL, NULL);
}
