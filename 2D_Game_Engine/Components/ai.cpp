#include "ai.h"

const int flockDistance = 200;

ai::ai()
{
    // Create getters and setters for these!
    m_aiState = AiState::MOVE_TOWARDS;
    m_Point1 = {300, 100};
    m_Point2 = {550, 100};
}

void ai::setPlayerPosition(SDL_Point playerPosition) {
    m_pPlayerPosition = playerPosition;
}

void ai::update(float deltaTime, Transform* transform) {
//    std::cout<<"Player "<<m_pPlayerPosition.x<<" "<<m_pPlayerPosition.y<<"\n";
    
    Entity *parentEntity = entity();
    
    if (m_aiState == AiState::MOVE_TOWARDS) {
        
        // Follow
        if (entity()->transform->m_tPosition.x - m_pPlayerPosition.x < flockDistance) {
            if (entity()->transform->m_tPosition.x - m_pPlayerPosition.x > 0)
                parentEntity->transform->m_tPosition.x--;
            else {
                parentEntity->transform->m_tPosition.x++;
            }
        }
    }
    
    else if (m_aiState == AiState::PATROL) {
        
        if (!m_DidHitPoint) {
            parentEntity->transform->m_tPosition.x++;
        }
        else if (parentEntity->transform->m_tPosition.x > m_Point1.x && m_DidHitPoint) {
            parentEntity->transform->m_tPosition.x--;
        }
        
        // Reset position
        if (abs(entity()->transform->m_tPosition.x - m_Point1.x) < 2) {
            m_DidHitPoint = false;
        }
        if (abs(entity()->transform->m_tPosition.x - m_Point2.x) < 2) {
            m_DidHitPoint = true;
        }
        
    }
    
}

void ai::setAiState(ai::AiState state) {
    m_aiState = state;
}

void ai::setPatrolPoints(SDL_Point point1, SDL_Point point2) {
    m_Point1 = point1;
    m_Point2 = point2;
}
