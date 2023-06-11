#pragma once

#include "../core/temperature_sensor.hpp"
#include "max6675.h"

class Max6675TemperatureSensor : public TemperatureSensor {
public:
    Max6675TemperatureSensor(int clkPin, int csPin, int misoPin);
    float getTemperatureCelcius();

private:
    MAX6675 _sensor;
};
