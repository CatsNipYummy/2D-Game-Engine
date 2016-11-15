#include "animation.h"

Animation::Animation()
{
    // Set current animation
    m_asCurrentState = IDLE;
}

void Animation::update(float deltaTime, Transform* transform) {
    Uint32 ticks = SDL_GetTicks();
    SDL_Rect srcRect;
    int sprite;
    
    switch (m_asCurrentState) {
        case IDLE:
            sprite = (ticks / 500) % 2;
            break;
        case JUMP:
            sprite = (ticks / 100) % 8;
            break;
        case RUN:
            sprite = (ticks / 100) % 10;
            break;
        default:
            break;
    }
    
    srcRect = {sprite * 60, 0, 60, 82};
    this->m_sSprite->setSubRect(srcRect);
    this->m_sSprite->setFrame({transform->m_tPosition.x, transform->m_tPosition.y, 60, 82});
}

void Animation::setSprite(Sprite *sprite) {
    this->m_sSprite = sprite;
}

void Animation::setState(AnimationState animationState) {
    m_asCurrentState = animationState;
    
    switch (m_asCurrentState) {
        case IDLE:
            this->m_sSprite->loadSprite("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_idle2.png");
            break;
        case JUMP:
            this->m_sSprite->loadSprite("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_jump2.png");
            break;
        case RUN:
            this->m_sSprite->loadSprite("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_running2.png");
            break;
        default:
            break;
    }
}
