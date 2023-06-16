/*
 * Implemenation of the timer using the Arduino library.
 *
 * Works using the arduino millis() function.
*/
#pragma once

#include <Arduino.h>
#include "time_provider.hpp"

class ArduinoTimeProvider : public TimeProvider
{
    long getTimeMillis();
};