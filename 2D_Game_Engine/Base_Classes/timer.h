#ifndef TIMER_H
#define TIMER_H


class Timer
{
private:
    int numFrames;
    double totalTime;
    double lastFrameTime, currentFrameTime;
    double deltaTime;
    
public:
    Timer();
    double printFPS();

};

#endif // TIMER_H
