#pragma once

#include "time_provider.hpp"

class Timer
{
public:
    Timer(TimeProvider *timeProvider, long intervalMilliseconds, bool repeating = true);
    bool isTriggered();
    long getIntervalMilliseconds();
    bool isRepeating();

private:
    TimeProvider *_timeProvider;
    bool _repeating;
    long _intervalMilliseconds;
    long _startTime;
    bool _intervalsPassedAtLastTrigger;
};