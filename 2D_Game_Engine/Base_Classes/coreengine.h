#ifndef COREENGINE_H
#define COREENGINE_H

#include <string>
#include<SDL2/SDL.h>
#include<renderer.h>

class CoreEngine
{
    Entity *m_character;
    Sprite *m_SpriteComponent;

public:
    CoreEngine();
    void createWindow(int height, int width, std::string name);
};

#endif // COREENGINE_H
