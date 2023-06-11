#pragma once

#include <Arduino.h>
#include "heater.hpp"

class SSRHeater : public Heater
{
public:
    SSRHeater(int pin);
    void enable();
    void disable();
    bool enabled();

private:
    int _pin;
};