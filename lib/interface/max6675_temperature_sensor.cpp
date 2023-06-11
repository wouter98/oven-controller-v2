#include "max6675_temperature_sensor.hpp"

Max6675TemperatureSensor::Max6675TemperatureSensor(int clkPin, int csPin, int misoPin)
    : _sensor(clkPin, csPin, misoPin)
{
}

float Max6675TemperatureSensor::getTemperatureCelcius()
{
    return _sensor.readCelsius();
}