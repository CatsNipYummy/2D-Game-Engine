#include "animation.h"

Animation::Animation()
{

}

void Animation::update(int deltaTime, Transform* transform) {

    Uint32 ticks = SDL_GetTicks();
    int sprite = (ticks / 100) % 10;
    SDL_Rect srcrect = {sprite * 290, 0, 290, 395 };
    this->m_sSprite->setSubRect(srcrect);
}

void Animation::setSprite(Sprite *sprite) {
    this->m_sSprite = sprite;
}
