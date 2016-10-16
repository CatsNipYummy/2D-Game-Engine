#ifndef TIMER_H
#define TIMER_H


class Timer
{
private:
    int numFrames;
    double totalTime;
public:
    Timer();
    double printFPS();

};

#endif // TIMER_H
