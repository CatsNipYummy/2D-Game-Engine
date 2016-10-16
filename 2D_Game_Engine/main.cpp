#include <iostream>
#include <window.h>
#include "entity.h"
#include "sprite.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
    Window window;
    window.createWindow(SCREEN_HEIGHT, SCREEN_WIDTH, "Test");
}
