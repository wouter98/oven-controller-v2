#include <Arduino.h>

#include "temperature_manager.hpp"
#include "max6675_temperature_sensor.hpp"

TemperatureManager manager;
Max6675TemperatureSensor sensor1(12, 9, 11);
Max6675TemperatureSensor sensor2(12, 10, 11);

void setup()
{
    Serial.begin();

    sleep(2);

    manager.addSensor(&sensor1);
    manager.addSensor(&sensor2);
}

void loop()
{
    Serial.print("Sensor 1 Temperature: ");
    Serial.print(sensor1.getTemperatureCelcius());
    Serial.println("c");

    Serial.print("Sensor 2 Temperature: ");
    Serial.print(sensor2.getTemperatureCelcius());
    Serial.println("c");

    Serial.print("Average Temperature: ");
    Serial.print(manager.getAverageTemperature());
    Serial.println("c");
    sleep(1);
}
