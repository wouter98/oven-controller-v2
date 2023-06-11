#pragma once

#include <vector>
#include "temperature_sensor.hpp"

class TemperatureManager
{
public:
    TemperatureManager();
    void addSensor(TemperatureSensor *sensor);
    float getAverageTemperature();
    int getSensorCount();
private:
    std::vector<TemperatureSensor *> _sensors;
};