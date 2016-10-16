#ifndef INPUT_H
#define INPUT_H

#include<SDL2/SDL.h>

class Input
{
public:
    Input();
    void getKeyData(SDL_KeyboardEvent *key);
};

#endif // INPUT_H
