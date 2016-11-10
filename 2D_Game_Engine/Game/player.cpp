#include "player.h"

Player::Player() : Entity("Character")
{
    // Character
    this->transform->setPosition({100,100});
    this->transform->setScale({1,1});
    this->transform->setRect({ 10, 10, 81, 104 });

    m_sSpriteComponent = new Sprite();
    m_sSpriteComponent->setName("Sprite_Component");
//   m_sSpriteComponent->loadBMPFromString("/home/milind/Pictures/dot.bmp");
//    m_sSpriteComponent->loadBMPFromString("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_running_bmp.bmp");
//    m_sSpriteComponent->loadSprite("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_running.png");
    m_sSpriteComponent->loadSprite("/home/milind/Desktop/2D_Game_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_running.png");

    SDL_Rect srcrect = {0, 0, 290, 395 };
    SDL_Rect dstrect = { 0, 0, 290, 395 };

    m_sSpriteComponent->setFrame(dstrect);
    m_sSpriteComponent->setSubRect(srcrect);
    this->addComponent(m_sSpriteComponent);

    m_aAnimation = new Animation();
    m_aAnimation->setName("Animation_Component");
    m_aAnimation->setSprite(m_sSpriteComponent);
    this->addComponent(m_aAnimation);

    EntityManager::addEntity(this);
}
