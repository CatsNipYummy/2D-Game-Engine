#ifndef ANIMATION_H
#define ANIMATION_H

#include "component.h"
#include "sprite.h"
#include <SDL2/SDL.h>

class Animation : public Component
{
private:
    Sprite *m_sSprite;
public:
    Animation();
    void setSprite (Sprite *sprite);
    void update(int deltaTime, Transform* transform);
};

#endif // ANIMATION_H
