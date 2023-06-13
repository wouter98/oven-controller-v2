#include <Arduino.h>

#include "config.hpp"
#include "temperature_manager.hpp"
#include "max6675_temperature_sensor.hpp"
#include "ssr_heater.hpp"

TemperatureManager manager;

Max6675TemperatureSensor sensor1(CLK_PIN, TEMP_SENSOR_1_PIN, MISO_PIN);
Max6675TemperatureSensor sensor2(CLK_PIN, TEMP_SENSOR_2_PIN, MISO_PIN);

SSRHeater heater(HEATER_PIN);

void setup()
{
    Serial.begin();

    sleep(2);

    manager.addSensor(&sensor1);
    manager.addSensor(&sensor2);
    manager.addHeater(&heater);
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

    Serial.print("Heater status: ");
    Serial.println(heater.enabled());

    if (manager.getAverageTemperature() > 50.0f)
    {
        heater.disable();
    }

    if (manager.getAverageTemperature() < 30.0f)
    {
        heater.enable();
    }

    sleep(1);
}
