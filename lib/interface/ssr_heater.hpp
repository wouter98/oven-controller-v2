/**
 * Implementation of the heater using an Solid-State Relay.
 *
 * Works by setting the heater pin to HIGH or LOW.
 */

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