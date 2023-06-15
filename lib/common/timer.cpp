#include "timer.hpp"

Timer::Timer(TimeProvider *timeProvider, long intervalMilliseconds, bool repeating)
    : _timeProvider(timeProvider), _repeating(repeating), 
    _intervalMilliseconds(intervalMilliseconds), _intervalsPassedAtLastTrigger(0)
{
    _startTime = _timeProvider->getTimeMillis();
}

bool Timer::isTriggered()
{
    long currentTime = _timeProvider->getTimeMillis();

    long timeDeltaMs = currentTime - _startTime;
    long intervalsPassed = timeDeltaMs / _intervalMilliseconds;

    // Return false if the timer is not set to repeat and has been triggered before 
    if (!_repeating && _intervalsPassedAtLastTrigger > 0) {
        return false;
    }

    // return true if more time than the specified interval has passed since the last trigger
    if (intervalsPassed > _intervalsPassedAtLastTrigger) {
        _intervalsPassedAtLastTrigger = intervalsPassed;
        return true;
    }

    return false;
}

long Timer::getIntervalMilliseconds()
{
    return _intervalMilliseconds;
}

bool Timer::isRepeating()
{
    return _repeating;
}