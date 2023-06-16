#pragma once

#include <vector>
#include "temperature_sensor.hpp"
#include "heater.hpp"
#include "pid_controller.hpp"
#include "time_provider.hpp"

class TemperatureManager
{
public:
    TemperatureManager(TimeProvider *timeProvider, PIDController *pidController);
    void addTemperatureSensor(TemperatureSensor *sensor);
    int getTemperatureSensorCount();
    float getAverageTemperature();

    void addHeater(Heater *heater);
    int getHeaterCount();
    void updateHeater(float targetTemperature);

    void setPIDController(PIDController *pidController);

private:
    void enableHeaters();
    void disableHeaters();

private:
    std::vector<TemperatureSensor *> _sensors;
    std::vector<Heater *> _heaters;
    TimeProvider *_timeProvider;
    PIDController *_pidController;
};