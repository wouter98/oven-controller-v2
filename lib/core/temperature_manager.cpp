#include "temperature_manager.hpp"

TemperatureManager::TemperatureManager(TimeProvider *timeProvider, PIDController *pidController)
    : _timeProvider(timeProvider), _pidController(pidController)
{
}

void TemperatureManager::addTemperatureSensor(TemperatureSensor *sensor)
{
    _sensors.push_back(sensor);
}

int TemperatureManager::getTemperatureSensorCount()
{
    return _sensors.size();
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

void TemperatureManager::addHeater(Heater *heater)
{
    _heaters.push_back(heater);
}

int TemperatureManager::getHeaterCount()
{
    return _heaters.size();
}

void TemperatureManager::updateHeater(float targetTemperature)
{
    float output = _pidController->calculateOutput(targetTemperature, getAverageTemperature());

    if (output >= 128) {
        enableHeaters();
    } else {
        disableHeaters();
    }
}

void TemperatureManager::setPIDController(PIDController *pidController)
{
    _pidController = pidController;
}

void TemperatureManager::enableHeaters()
{
    for (Heater *heater : _heaters) {
        heater->enable();
    }
}

void TemperatureManager::disableHeaters()
{
    for (Heater *heater : _heaters) {
        heater->disable();
    }
}
