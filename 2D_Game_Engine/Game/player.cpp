#include "player.h"

Player::Player() : Entity("Character")
{
    // Character
    this->transform->setPosition({0,0});
    this->transform->setScale({1,1});
//    this->transform->setRect({ 10, 10, 30, 35 });

    m_sSpriteComponent = new Sprite();
    m_sSpriteComponent->setName("Sprite_Component");
    //m_sSpriteComponent->loadSprite("/home/milind/Desktop/2D_Game_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_running.png");
//    m_sSpriteComponent->loadBMPFromString("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_running_bmp.bmp");

//    m_sSpriteComponent->loadSprite("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_running.png");
    m_sSpriteComponent->loadSprite("/home/milind/Desktop/2D_Game_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_running.png");

   // m_sSpriteComponent->loadSprite("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_idle2.png");


    SDL_Rect srcrect = {0, 0, 60, 82 };
    SDL_Rect dstrect = { 0, 0, 60, 82 };

    m_sSpriteComponent->setFrame(dstrect);
    m_sSpriteComponent->setSubRect(srcrect);
    this->addComponent(m_sSpriteComponent);

    m_aAnimation = new Animation();
    m_aAnimation->setName("Animation_Component");
    m_aAnimation->setSprite(m_sSpriteComponent);
    this->addComponent(m_aAnimation);

    EntityManager::addEntity(this);
    
    // Set Velocity
    m_fVelocityX = 2.0f;
    m_fVelocityY = -2.0f;
}

void Player::setInput(SDL_Event &event) {
    m_Event = &event;
    
    switch (m_Event->type) {
        case SDL_KEYDOWN:
        {
            switch(m_Event->key.keysym.sym)
            {
                case SDLK_RIGHT:
                {
                    m_aAnimation->setState(Animation::RUN);
                    break;
                }
                case SDLK_LEFT:
                {
                    m_aAnimation->setState(Animation::RUN);
                    break;
                }
                case SDLK_SPACE:
                {
                    m_aAnimation->setState(Animation::JUMP);
                    if (m_fVelocityY >= 10.0f || m_bJumpPressed) {
                        m_fVelocityY = -5.0f;
                    }
                    else if (!m_bJumpPressed) {
                        m_fVelocityY += 5.0f;
                        m_bJumpPressed = true;
                        m_fVelocityX = 4.0f;
                    }
                    break;
                }
            }
            break;
        }
        case SDL_KEYUP: {
            switch(m_Event->key.keysym.sym)
            {
                case SDLK_RIGHT:
                {
                    m_aAnimation->setState(Animation::IDLE);
                    break;
                }
                case SDLK_LEFT:
                {
                    m_aAnimation->setState(Animation::IDLE);
                    break;
                }
                case SDLK_SPACE:
                {
                    m_aAnimation->setState(Animation::JUMP);
                    m_fVelocityY = -5.0f;
                    m_bJumpPressed = false;
                    break;
                }
            }
            break;
        }
    }
}

float Player::velocityX() {
    return m_fVelocityX;
}

float Player::velocityY() {
    return m_fVelocityY;
}

void Player::setVelocityX(float velocityX) {
    m_fVelocityX = velocityX;
}

void Player::setVelocityY(float velocityY) {
    m_fVelocityY = velocityY;
}

void Player::setInAir (bool inAir) {
    m_bInAir = inAir;
}

void Player::setAnimationState (Animation::AnimationState animationState) {
    m_asAnimationState = animationState;
    m_aAnimation->setState(animationState);
}

bool Player::jumpPressed () {
    return m_bJumpPressed;
}
