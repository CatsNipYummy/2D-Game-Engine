#include "player.h"

Player::Player() : Entity("Character")
{
    // Character
    this->transform->setPosition({100,100});
    this->transform->setScale({1,1});

    m_sSpriteComponent = new Sprite();
    m_sSpriteComponent->setName("Sprite_Component");
    m_sSpriteComponent->loadBMPFromString("/Users/anil/Downloads/Tutorials/30_scrolling/dot.bmp");

    this->addComponent(m_sSpriteComponent);

    EntityManager::addEntity(this);

}
