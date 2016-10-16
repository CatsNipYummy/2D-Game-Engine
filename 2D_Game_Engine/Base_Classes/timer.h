#ifndef TIMER_H
#define TIMER_H


class Timer
{
private:
    int numFrames;
    long totalTime;
public:
    Timer();
    void printFPS();

};

#endif // TIMER_H
