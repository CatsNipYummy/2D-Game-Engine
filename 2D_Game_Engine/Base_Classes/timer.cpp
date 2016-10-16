#include "timer.h"
#include <SDL2/SDL.h>
#include<iostream>
#include "coreengine.h"

Timer::Timer()
{
    numFrames=0;
    totalTime=0;
}

int Timer::printFPS()
{
    const Uint32 startTime = SDL_GetTicks();
    SDL_Delay( 1.0f/60.0f );
    const Uint32 endTime = SDL_GetTicks();

    totalTime = endTime - startTime;
    //++numFrames;
    //float fps = numFrames / (totalTime / 1000.0);
    return totalTime;
}
