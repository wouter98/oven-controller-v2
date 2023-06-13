#include "temperature_manager.hpp"

void TemperatureManager::addSensor(TemperatureSensor *sensor)
{
    _sensors.push_back(sensor);
}

void TemperatureManager::addHeater(Heater *heater)
{
    _heaters.push_back(heater);
}

int TemperatureManager::getSensorCount()
{
    return _sensors.size();
}

int TemperatureManager::getHeaterCount()
{
    return _heaters.size();
}

float TemperatureManager::getAverageTemperature()
{
    float totalTemperature = 0;

    if (_sensors.empty())
    {
        return 0.0f;
    }

    for (TemperatureSensor *sensor : _sensors)
    {
        totalTemperature += sensor->getTemperatureCelcius();
    }

    return totalTemperature / _sensors.size();
}

void TemperatureManager::setTargetTemperature(int degreesCelsius)
{
    _targetTemperatureCelsius = degreesCelsius;
}

void TemperatureManager::loop()
{
    
}
