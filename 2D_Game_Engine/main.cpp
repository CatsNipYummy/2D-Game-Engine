#include <iostream>
#include <coreengine.h>
#include "entity.h"
#include "sprite.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
    CoreEngine coreEngine;
    coreEngine.createWindow(SCREEN_HEIGHT, SCREEN_WIDTH, "Test");
}
