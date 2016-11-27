#ifndef AI_H
#define AI_H

#include "component.h"

class ai : public Component
{
private:
    SDL_Point m_pPlayerPosition;
    enum AiState {
        MOVE_TOWARDS,
        PATROL
    };
    AiState m_aiState;
    
    // Patrol Points
    SDL_Point m_Point1;
    SDL_Point m_Point2;
    bool m_DidHitPoint = true;
    
public:
    ai();
    void setPlayerPosition(SDL_Point playerPosition);
    void update(float deltaTime, Transform* transform);
    void setAiState (AiState state);
    void setPatrolPoints(SDL_Point point1, SDL_Point point2);
};

#endif // AI_H
