#include "player.h"

Player::Player() : Entity("Character")
{
    // Character
    m_eCharacter = new Entity("Character");
    m_eCharacter->transform->setPosition({100,100});
    m_eCharacter->transform->setScale({1,1});

    m_sSpriteComponent = new Sprite();
    m_sSpriteComponent->setName("Sprite_Component");
    m_sSpriteComponent->loadBMPFromString("/Users/anil/Downloads/Tutorials/30_scrolling/dot.bmp");

    m_eCharacter->addComponent(m_sSpriteComponent);

    EntityManager::addEntity(m_eCharacter);
}
