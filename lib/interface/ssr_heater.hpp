/**
 * Implementation of the heater using an Solid-State Relay.
 *
 * Works by setting the heater pin to HIGH or LOW.
 */

#pragma once

#include <Arduino.h>
#include "heater.hpp"
#include "timer.hpp"

class SSRHeater : public Heater
{
public:
    SSRHeater(int pin);
    void setPower(float power);
    float getPower();

private:
    int _pin;
    float _power;
};