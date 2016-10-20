#include "player.h"

Player::Player() : Entity("Character")
{
    // Character
    this->transform->setPosition({100,100});
    this->transform->setScale({1,1});

    m_sSpriteComponent = new Sprite();
    m_sSpriteComponent->setName("Sprite_Component");
   m_sSpriteComponent->loadBMPFromString("/home/milind/Pictures/dot.bmp");
   //m_sSpriteComponent->loadBMPFromString("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/dot.bmp");
    this->addComponent(m_sSpriteComponent);

    EntityManager::addEntity(this);

}
