#include "world.h"

const float VELOCITY = 2.0f;

World::World()
{
    m_pGravity = -20.0f;
}

void World::update(float deltaTime, Transform* transform) {

    // Jump
    if (m_Player != nullptr) {
        if (deltaTime > 0.07f) {
            deltaTime = 0.07f;
        }

        m_fTempX = m_Player->transform->m_tPosition.x + (m_Player->velocityX() * deltaTime);

        // Hardcoded 180
        if (m_fTempY < 180.0f) {
            m_fTempY = m_Player->transform->m_tPosition.y - m_Player->velocityY();
            m_Player->setInAir(true);
        }
        else if (!m_Player->jumpPressed()) {
            m_Player->setVelocityY(0.0f);
            m_Player->setInAir(false);
            m_Player->setAnimationState(Animation::AnimationState::RUN);
        }

        m_fTempY = m_Player->transform->m_tPosition.y - m_Player->velocityY();


        m_Player->transform->setPosition({static_cast<int>(m_fTempX), static_cast<int>(m_fTempY)});
    }
}

void World::setEntity(Entity *entity) {
    m_entity = entity;
}

void World::setPlayer(Player *player) {
    m_Player = player;
}
