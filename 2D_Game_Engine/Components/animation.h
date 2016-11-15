#ifndef ANIMATION_H
#define ANIMATION_H

#include "component.h"
#include "sprite.h"
#include <SDL2/SDL.h>

class Animation : public Component
{
public:
    
    enum AnimationState {
        IDLE,
        RUN,
        JUMP
    };
    
    Animation();
    void setSprite (Sprite *sprite);
    void update(float deltaTime, Transform* transform);
    void setState(AnimationState animationState);
    
private:
    AnimationState m_asCurrentState;
    Sprite *m_sSprite;
};

#endif // ANIMATION_H
