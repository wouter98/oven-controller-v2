/* 
 * Implementation of the temperature sensor using a Max6675 temperature sensor.
 *
 * Works using the adafruit/MAX6675 library.
*/
#pragma once

#include "temperature_sensor.hpp"
#include "max6675.h"

class Max6675TemperatureSensor : public TemperatureSensor {
public:
    Max6675TemperatureSensor(int clkPin, int csPin, int misoPin);
    float getTemperatureCelcius();

private:
    MAX6675 _sensor;
};
