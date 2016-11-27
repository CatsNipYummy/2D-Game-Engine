#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "entity.h"
#include "entitymanager.h"
#include "component.h"
#include "sprite.h"
#include "animation.h"
#include "collision.h"
#include "collisionmanager.h"

class Player : public Entity
{
private:
    Sprite *m_sSpriteComponent;
    Animation *m_aAnimation;
    Animation::AnimationState m_asAnimationState;
    Collision *m_PlayerCollision;
    SDL_Event *m_Event;
    
    float m_fVelocityX;
    float m_fVelocityY;
    bool m_bInAir = false;
    bool m_bJumpPressed = false;

    bool m_bFlip=false;
    
public:
    Player();
    void update(int x,int y);
    void setFlip(bool val);
    void setInput(SDL_Event &event);
    void jump();
    float velocityX();
    float velocityY();
    void setInAir (bool inAir);
    void setVelocityX(float velocityX);
    void setVelocityY(float velocityY);
    void setAnimationState (Animation::AnimationState animationState);
    bool jumpPressed ();
    
};

#endif // PLAYER_H
