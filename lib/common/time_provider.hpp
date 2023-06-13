#pragma once

class TimeProvider
{
public:
    virtual long getTimeMillis() = 0;
};