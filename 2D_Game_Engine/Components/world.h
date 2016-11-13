#ifndef WORLD_H
#define WORLD_H
#include "component.h"

class World : public Component
{
public:
    World();
    void update(int deltaTime, Transform* transform);
};

#endif // WORLD_H
