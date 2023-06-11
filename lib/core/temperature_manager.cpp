#include "temperature_manager.hpp"

TemperatureManager::TemperatureManager()
{
}

void TemperatureManager::addSensor(TemperatureSensor *sensor)
{
    _sensors.push_back(sensor);
}

float TemperatureManager::getAverageTemperature()
{
    float totalTemperature = 0;

    if (_sensors.empty()) {
        return 0.0f;
    }

    for (TemperatureSensor *sensor : _sensors)
    {
        totalTemperature += sensor->getTemperatureCelcius();
    }

    return totalTemperature / _sensors.size();
}

int TemperatureManager::getSensorCount()
{
    return _sensors.size();
}