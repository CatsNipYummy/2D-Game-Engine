#ifndef COREENGINE_H
#define COREENGINE_H

#include <string>
#include<SDL2/SDL.h>
#include<renderer.h>

class CoreEngine
{

public:
    CoreEngine();
    void createWindow(int height, int width, std::string name);
};

#endif // COREENGINE_H
