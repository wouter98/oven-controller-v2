#pragma once

#include <vector>
#include "temperature_sensor.hpp"
#include "heater.hpp"
#include "pidcontroller.h"

class TemperatureManager
{
public:
    void addSensor(TemperatureSensor *sensor);
    void addHeater(Heater *heater);
    int getSensorCount();
    int getHeaterCount();
    float getAverageTemperature();
    void setTargetTemperature(int degreesCelsius);
    void loop();

private:
    std::vector<TemperatureSensor *> _sensors;
    std::vector<Heater *> _heaters;

    int _targetTemperatureCelsius;
    long _previousTimeMillis;
};