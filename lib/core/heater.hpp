#pragma once

class Heater
{
public:
    virtual void enable() = 0;
    virtual void disable() = 0;
};